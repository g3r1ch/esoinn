#ifndef PERCEPTRON_H
#define PERCEPTRON_H

#include <vector>
#include <iostream>	
#include <ctime>

using namespace std;

class Perc {
private:
	double sigmoid(double x);
	double dActivationFunction(double x);

	double summ;
	double out;
	vector <double> W;
	vector <double> input;
	double learningRate;
	double mOffset;
	int M = 0;
	double h = 0;
	int classID = 0;
	bool isNew = 0;

public:
	//Perc(int aCountOfW, double aLearningRate = 0.3);
	Perc(int aCountOfW, int random, double aLearningRate = 0.3, bool added = 0);
	double process(vector<double> aInput);
	void changeWeights(bool isWinner);
	double output();
	//void init(int aCountOfW, double aLearningRate);
	vector<double> ret_w();
	void set_w(vector<double> a);
	int getClass();
	void setClass(int newID);
	double getDensity();
	void changeNew();
	bool getNew();
	void increaseM();
	void upgradeDensity(double meanDensity);
};
#endif // !Perceptron