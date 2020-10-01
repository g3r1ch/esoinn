#ifndef NEURAL_NETWORK_H
#define NEURAL_NETWORK_H

#include "percLayer.h"
#include "norm.h"
#include "outputLayer.h"
#include "layer.h"


class Network {
private:
	vector<Layer*> layers;
	vector<double> answered = {};
public:
	enum LayerType { NORM, PERC, OUTPUTLAYER };
	Network(std::vector<LayerType> aLayersType, int aInpNeuronsCol, int aNeyronsCount, int maxAge, int aMaxInpSize, double aLerningRate, int count_of_points, int aY, double aC1, double aC2);//TODO: aColOfLayers
	~Network();
	double process(vector<double> aInp);
	void correct();
	vector<double> get_w(int aLayer, int aNeuron);
	int size(int aLayer);
};


#endif