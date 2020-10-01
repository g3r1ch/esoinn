#include "norm.h"

using namespace std;

Norm::Norm(int aDel) {
	del = aDel;
}

vector <double> Norm::process(const vector <double> aInp) {
	vector <double> out;
	for (int i = 0; i < aInp.size(); i++) {
		//out[i] = aInp[i] / del;
		out.emplace_back(aInp[i] / del);
	}
	return out;
}

//double Norm::norm(double inp) {
//	return inp / del;
//}

vector<double> Norm::correct(const vector<double> aInp) {
	return aInp;
}

int Norm::size() const {
	return del;
}