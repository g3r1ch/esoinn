#include "outputLayer.h"

using namespace std;

OutputLayer::OutputLayer(int aConnectionsCount) {
	connectionsCount = aConnectionsCount;
}

vector<double> OutputLayer::process(const vector <double> aInp) {
	int num = 0;
	int num2 = 0;
	for (int i = 0; i < aInp.size(); i++) {
		/*cout << endl << "			" << i << endl;*/
		if (aInp[i] < aInp[num]) {
			num = i;
		}
		else if (aInp[i] < aInp[num2]) {
			num2 = i;
		}
	}
	return {double(num) , double(num2)};
	//int num = 0;
	//for (int i = 0; i < aInp.size(); i++) {
	//	/*cout << endl << "      " << i << endl;*/
	//	if (abs(aInp[i] - 0.5) < abs(aInp[num] - 0.5))
	//		num = i;
	//}
	//return { double(num) };
}

double OutputLayer::activationFunction(double aS)
{
	return 1. / (1. + exp(-aS));
}

vector <double> OutputLayer::correct(const vector<double> aInp) {
	//if(aInp[0])
	//	aInp[0] -= 1;
	/*double a = 0.5 / (connectionsCount * 1.);
	vector <double> res(connectionsCount);
	double lcl = 0.5;
	for (int i = aInp[0] - 1; i >= 0; i--) {
		lcl += a;
		res[i] = lcl;
	}
	res[aInp[0]] = 0.5;
	lcl = 0.5;
	for (int i = aInp[0] + 1; i < res.size(); i++) {
		lcl -= a;
		res[i] = lcl;
	}
	return res;*/
	/*double a = 1. / (connectionsCount * 1.);
	vector <double> res(connectionsCount);
	double lcl = 1.;
	for (int i = aInp[0] - 1; i >= 0; i--) {
		lcl -= a;
		res[i] = lcl;
	}
	res[aInp[0]] = 1.;
	lcl = 1.;
	for (int i = aInp[0] + 1; i < res.size(); i++) {
		lcl -= a;
		res[i] = lcl;
	}
	return res;*/

	/*vector<double> result(connectionsCount);
	for (int i = 0; i < result.size(); ++i)
	{
		result[i] = activationFunction((i - aInp[0]) / 500);
	}
	return result;*/
	return aInp;
}

int OutputLayer::size() const {
	return connectionsCount;
}