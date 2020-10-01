#include "perceptron.h"

using namespace std;

Perc::Perc(int aCountOfW, int random, double aLearningRate, bool added) :
	W(aCountOfW),
	input(0)
{
	if (!added) {
		srand(time(0));
		for (int i = 0; i < aCountOfW; i++) {
			W[i] = (random % 1000) / 1000.;
		}
	}
	mOffset = (random % 1000 - 500) / 1000.;
	learningRate = aLearningRate;
}

double Perc::process(vector<double> aInput) {
	/*input = aInput;
	summ = 0;
	for (int i = 0; i < W.size(); i++) {
		summ += W[i] * (aInput)[i];
	}
	summ += mOffset;
	out = sigmoid(summ);
	return out;*/
	summ = 0;
	input = aInput;

	for (int i = 0; i < W.size(); i++) {
		summ += (aInput[i] - W[i]) * (aInput[i] - W[i]);
	}

	return sqrt(summ);
}

//Perc::Perc() {
//
//}
//
//void Perc::init(int aCountOfW, double aLearningRate) {
//	for (int i = 0; i < aCountOfW; i++) {
//		W.push_back((rand() % 1000 - 500) / 1000.);
//	}
//	mOffset = (rand() % 1000 - 500) / 1000.;
//	learningRate = aLearningRate;
//}

void Perc::changeWeights(bool isWinner) {
	/*double err = aAnswer - out;
	double nechto = err * dActivationFunction(summ);
	for (int i = 0; i < W.size(); i++) {
		W[i] += learningRate * nechto * (input)[i];
	}
	mOffset += learningRate * nechto;*/
	double e;
	if (isWinner) {
		e = 1 / double(M);
	}
	else {
		e = 1 / (100 * double(M));
	}
	for (int i = 0; i < W.size(); i++) {
		W[i] = W[i] + learningRate * (input[i] - W[i]) * e;
	}
}

double Perc::output() {
	return out;
}

//\\private

double Perc::sigmoid(double x) {
	return 1. / (1. + exp(-x));
}

double Perc::dActivationFunction(double x) {
	return sigmoid(x) * (1. - sigmoid(x));
}

vector<double> Perc::ret_w() {
	return W;
}

void Perc::set_w(vector<double> a) {
	for (int i = 0; i < W.size(); i++) {
		W[i] = a[i];
	}
}

int Perc::getClass() {
	return classID;
}

void Perc::setClass(int newID) {
	classID = newID;
}

double Perc::getDensity() {
	return h;
}

void Perc::changeNew() {
	isNew = !isNew;
}

bool Perc::getNew() {
	return isNew;
}

void Perc::increaseM() {
	M++;
}

void Perc::upgradeDensity(double meanDensity) {
	h = 1 / (double(M) * (1 + meanDensity) * (1 + meanDensity));
}