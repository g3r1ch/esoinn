#ifndef OUTPUTLAYER_H
#define OUTPUTLAYER_H

#include <vector>
#include <iostream>	
#include "layer.h"

using namespace std;

class OutputLayer : public Layer {
private:
	int connectionsCount;
	double activationFunction(double aS);
public:
	OutputLayer(int aConnectionsCount);
	virtual vector<double> process(const vector<double> aInp);
	virtual vector<double> correct(const vector<double> aInp);
	virtual int size() const;
};

#endif // !OUTPUTLAYER_H
