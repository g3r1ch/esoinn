#include "percLayer.h"
//Layer::Layer(int aCountOfNeyrons, int aCountOfInputs, double aLearningRate) :
//	neyro(0)
//{
//	for (int i = 0; i < aCountOfNeyrons; ++i)
//	{
//		neyro.emplace_back(Perc());
//		neyro[i].init(aCountOfInputs, aLearningRate);
//	}
//}

PercLayer::PercLayer(int aCountOfNeyrons, int aCountOfInputs, double aLearningRate, int aCount_of_points, int amaxAge, int aY, double aC1, double aC2)/* :
	neyro(aCountOfNeyrons, Perc(aCountOfInputs, rand()))*/
{
	srand(time(0));
	for (int i = 0; i < aCountOfNeyrons; i++) {
		neyro.push_back(Perc(aCountOfInputs, rand(), aLearningRate));
		neyro[neyro.size() - 1].setClass(lastClassID);
		lastClassID++;
	}
	//dist = distance;
	count_of_points = aCount_of_points;
	learningRate = aLearningRate;
	maxAge = amaxAge;
	yY = aY;
	C1 = aC1;
	C2 = aC2;
}

vector <double> PercLayer::process(const vector <double> aInp) {
	input = aInp;
	vector <double> res;
	for (auto& i : neyro) {
		res.push_back(i.process(aInp));
	}
	return res;
}

vector<double> PercLayer::correct(const vector <double> aInp) {
	counter++;
	vector<double> sampleWeights = neyro[int(aInp[0])].ret_w();
	vector<double> sampleWeights2 = neyro[int(aInp[1])].ret_w();
	bool f = 0;
	bool f2 = 0;
	double max = 0;
	double max2 = 0;
	double T1;
	double T2;
	for (int i = 0; i < connections.size(); i++) {
		if (distance(sampleWeights, neyro[connections[i][0]].ret_w()) > max && connections[i][1] == int(aInp[0])) {
			max = distance(sampleWeights, neyro[connections[i][0]].ret_w());
			f = 1;
		}
		else if (distance(sampleWeights, neyro[connections[i][1]].ret_w()) > max && connections[i][0] == int(aInp[0])) {
			max = distance(sampleWeights, neyro[connections[i][1]].ret_w());
			f = 1;
		}

		if (distance(sampleWeights2, neyro[connections[i][0]].ret_w()) > max2 && connections[i][1] == int(aInp[1])) {
			max2 = distance(sampleWeights2, neyro[connections[i][0]].ret_w());
			f2 = 1;
		}
		else if (distance(sampleWeights2, neyro[connections[i][1]].ret_w()) > max2 && connections[i][0] == int(aInp[1])) {
			max = distance(sampleWeights2, neyro[connections[i][1]].ret_w());
			f2 = 1;
		}
	}
	T1 = max;
	T2 = max2;
	if (f) {
		double min = INFINITY;
		for (int i = 0; i < neyro.size(); i++) {
			if (i == int(aInp[0])) {
				continue;
			}
			if (distance(sampleWeights, neyro[i].ret_w()) < min) {
				min = distance(sampleWeights, neyro[i].ret_w());
			}
		}
		T1 = min;
	}
	if (f2) {
		double min = INFINITY;
		for (int i = 0; i < neyro.size(); i++) {
			if (i == int(aInp[1])) {
				continue;
			}
			if (distance(sampleWeights2, neyro[i].ret_w()) < min) {
				min = distance(sampleWeights2, neyro[i].ret_w());
			}
		}
		T2 = min;
	}
	if (distance(sampleWeights, input) > T1 || distance(sampleWeights2, input) > T2) {
		neyro.push_back(Perc(input.size(), 0, learningRate, 1));
		neyro[neyro.size() - 1].set_w(input);
		neyro[neyro.size() - 1].setClass(lastClassID);
		neyro[neyro.size() - 1].changeNew();
		lastClassID++;
		return {};
	}

	//---------------------------------------

	ageIncrease(int(aInp[0]));

	//---------------------------------------

	if (needMerge(int(aInp[0]),int(aInp[1])) || neyro[int(aInp[0])].getClass() == neyro[int(aInp[1])].getClass() || neyro[int(aInp[1])].getNew() == 1 || neyro[int(aInp[0])].getNew() == 1) {
		if (connectionExsist(int(aInp[0]), int(aInp[1])) == -1) {
			connections.push_back({ int(aInp[0]) ,int(aInp[1]) ,0 });
		}
		else {
			connections[connectionExsist(int(aInp[0]), int(aInp[1]))][2] = 0;
		}
	}
	else if (connectionExsist(int(aInp[0]), int(aInp[1])) != -1) {
		connections[connectionExsist(int(aInp[0]), int(aInp[1]))] = { -1,-1,-1 };
	}

	//---------------------------------------
	
	neyro[int(aInp[0])].increaseM();

	//---------------------------------------

	neyro[int(aInp[0])].upgradeDensity(meanDensity(neyro[int(aInp[0])].getClass()));

	//---------------------------------------

	neyro[int(aInp[0])].changeWeights(1);

	//---------------------------------------

	deleteOldConnections();

	//---------------------------------------

	if (counter % yY == 0) {
		updateClasses();

		//---------------------------------------

		deleteNoise();
	}

	/*for (int i = 0; i < neyro.size(); i++){
		vector<double> weights = neyro[i].ret_w();
		double summ = 0;

		for (int j = 0; j < sampleWeights.size(); j++) {
			summ += (sampleWeights[j] - weights[j]) * (sampleWeights[j] - weights[j]);
		}
		if (sqrt(summ) <= (dist - (dist/(5000 * count_of_points))*counter)) {
			neyro[i].changeWeights();
		}
	}
	counter++;
	return{};*/
}

//void PercLayer::correct(double ans) {
//	for (int i = 0; i < neyro.size(); i++)
//	{
//		neyro[i].changeWeights(ans);
//	}
//}

int PercLayer::size() const {
	return neyro.size();
}

vector<double> PercLayer::get_w(int num_of_perc, bool flag) {
	vector<double> out;
	if (num_of_perc < 0) {
		out = { -1 };
		return out;
	}else if (flag) {
		for (int i = 0; i < neyro.size(); i++) {
			out.push_back(neyro[i].ret_w()[num_of_perc]);
		}
	}
	else {
		out = neyro[num_of_perc].ret_w();
	}
	return out;
}

double PercLayer::distance(vector<double> v1, vector<double> v2) {
	double summ = 0;
	for (int i = 0; i < v1.size(); i++) {
		summ += (v1[i] - v2[i]) * (v1[i] - v2[i]);
	}

	return sqrt(summ);
}

void PercLayer::ageIncrease(int a) {
	for (int i = 0; i < connections.size(); i++) {
		if (connections[i][0] == a || connections[i][1]) {
			connections[i][2]++;
		}
	}
}

double PercLayer::meanDensity(int classID) {
	double summ = 0;
	int n = 0;
	for (int i = 0; i < neyro.size(); i++) {
		if (neyro[i].getClass() == classID) {
			summ += neyro[i].getDensity();
			n++;
		}
	}
	return summ / double(n);
}

double PercLayer::maxDensity(int classID) {
	double max = -1;
	for (int i = 0; i < neyro.size(); i++) {
		if (neyro[i].getClass() == classID && neyro[i].getDensity() > max) {
			max = neyro[i].getDensity();
		}
	}
	return max;
}

double PercLayer::densityThershold(double mean, double max) {
	if (2. * mean >= max) {
		return 0.;
	}
	if (3. * mean >= max) {
		return 0.5;
	}
	return 1.;
}

bool PercLayer::needMerge(int a, int b) {
	double meanA = meanDensity(neyro[a].getClass());
	double meanB = meanDensity(neyro[b].getClass());
	double maxA = maxDensity(neyro[a].getClass());
	double maxB = maxDensity(neyro[b].getClass());
	if (neyro[a].getDensity() < neyro[b].getDensity()) {
		if (neyro[a].getDensity() > densityThershold(meanA, maxA)) {
			return 1;
		}
		if (neyro[a].getDensity() > densityThershold(meanB, maxB)) {
			return 1;
		}
	}
	else {
		if (neyro[b].getDensity() > densityThershold(meanA, maxA)) {
			return 1;
		}
		if (neyro[b].getDensity() > densityThershold(meanB, maxB)) {
			return 1;
		}
	}
	return 0;
}

int PercLayer::connectionExsist(int a1, int a2) {
	for (int i = 0; i < connections.size(); i++) {
		if ((connections[i][0] == a1 && connections[i][1] == a2) || (connections[i][1] == a1 && connections[i][0] == a2)) {
			return i;
		}
	}
	return -1;
}

void PercLayer::deleteOldConnections() {
	for (int i = 0; i < connections.size(); i++) {
		if (connections[i][2] > maxAge) {
			connections[i] = { -1,-1,-1 };
		}
	}
}

void PercLayer::updateClasses() {
	for (int i = 0; i <= neyro.size(); i++) {
		for (int j = 0; j <= neyro.size(); j++) {
			if (i == j) {
				continue;
			}
			if (needMerge(i, j)) {
				for (int o = 0; o < neyro.size(); o++) {
					if (neyro[o].getClass() == neyro[i].getClass()) {
						neyro[o].setClass(neyro[j].getClass());
					}
				}
			}
		}
	}
}

void PercLayer::deleteNoise() {
	vector<int> count(neyro.size(), 0);
	double summ = 0;
	for (int i = 0; i < connections.size(); i++) {
		count[connections[i][0]]++;
		count[connections[i][1]]++;
	}
	for (int i = 0; i < neyro.size(); i++) {
		summ += neyro[i].getDensity() / neyro.size();
	}

	for (int i = 0; i < count.size(); i++) {
		if (count[i] == 2 && neyro[i].getDensity()<(C1*summ)) {
			neyro.erase(neyro.begin() + i);
			for (int o = 0; o < connections.size(); o++) {
				if (connections[o][0] > i) {
					connections[o][0]--;
				}
				if (connections[o][1] > i) {
					connections[o][1]--;
				}
				if (connections[o][0] == i) {
					connections[o] = { -1,-1,-1 };
				}
				if (connections[o][1] == i) {
					connections[o] = { -1,-1,-1 };
				}
			}
		}else if (count[i] == 1 && neyro[i].getDensity() < (C2 * summ)) {
			neyro.erase(neyro.begin() + i);
			for (int o = 0; o < connections.size(); o++) {
				if (connections[o][0] > i) {
					connections[o][0]--;
				}
				if (connections[o][1] > i) {
					connections[o][1]--;
				}
				if (connections[o][0] == i) {
					connections[o] = { -1,-1,-1 };
				}
				if (connections[o][1] == i) {
					connections[o] = { -1,-1,-1 };
				}
			}
		}else if (count[i] == 0) {
			neyro.erase(neyro.begin() + i);
			for (int o = 0; o < connections.size(); o++) {
				if (connections[o][0] > i) {
					connections[o][0]--;
				}
				if (connections[o][1] > i) {
					connections[o][1]--;
				}
				if (connections[o][0] == i) {
					connections[o] = { -1,-1,-1 };
				}
				if (connections[o][1] == i) {
					connections[o] = { -1,-1,-1 };
				}
			}
		}
	}
}

//vector<double> PercLayer::hWinners(int classID) {
//	double h1 = -INFINITY;
//	double h2 = -INFINITY;
//	for (int i = 0; i < neyro.size(); i++) {
//		if (neyro[i].getDensity() > h1) {
//			h1 = neyro[i].getDensity();
//		} else if (neyro[i].getDensity() > h2) {
//			h2 = neyro[i].getDensity();
//		}
//	}
//	return { h1,h2 };
//}