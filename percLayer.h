#ifndef PERC_LAYER_H
#define PERC_LAYER_H

#include <vector>
#include <iostream>
#include <ctime>
#include "perceptron.h"
#include "layer.h"

using namespace std;

class PercLayer : public Layer {
private:
	vector <Perc> neyro;
	vector<vector<int>> connections = {};
	//double dist;
	int counter = 0;
	int count_of_points = 1;
	int lastClassID = 1;
	int maxAge = 0;
	int yY = 0;
	double C1, C2;
	double learningRate = 0.3;
	vector<double> input;
	double distance(vector<double> v1, vector<double> v2);
	void ageIncrease(int a);
	double meanDensity(int classID);
	double maxDensity(int classID);
	double densityThershold(double mean, double max);
	bool needMerge(int a, int b);
	int connectionExsist(int a1, int a2);
	void deleteOldConnections();
	void updateClasses();
	//vector<double> hWinners(int classID);
	void deleteNoise();
public:
	PercLayer(int aCountOfNeyrons, int aCountOfInputs, double aLearningRate, int aCount_of_points, int amaxAge, int aY, double aC1, double aC2);
	virtual vector<double> process(const vector <double> aInp);
	virtual vector<double> correct(const vector <double> aInp);
	//virtual void correct(double ans);
	virtual int size() const;
	virtual vector<double> get_w(int num_of_perc, bool flag);
};

#endif // !LAYER_