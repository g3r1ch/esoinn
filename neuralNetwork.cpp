#include "neyralNetwork.h"

Network::Network(std::vector<LayerType> aLayersType, int aInpNeuronsCol, int aNeyronsCount, int maxAge, int aMaxInpSize, double aLearningRate, int count_of_points, int aY, double aC1, double aC2) {
	for (auto& i : aLayersType) {
		if (i == LayerType::NORM) {
			layers.emplace_back(new Norm(aMaxInpSize));
		}
		else if (i == LayerType::PERC) {
			layers.emplace_back(new PercLayer(aNeyronsCount, aInpNeuronsCol, aLearningRate, count_of_points, maxAge, aY,aC1,aC2));
		}
		else if (i == LayerType::OUTPUTLAYER) {
			layers.emplace_back(new OutputLayer(aNeyronsCount));
		}
	}
}

Network::~Network()
{
	for (auto& i : layers)
	{
		delete(i);
	}
}

double Network::process(vector<double> aInp) {
	for (auto& i : layers) {
		aInp = i->process(aInp);
	}
	answered = aInp;
	return aInp[0];
}

void Network::correct() {
	vector<double> anss = answered;
	for (int i = layers.size()-1; i >= 0; i--) {
		anss = layers[i]->correct(anss);
	}
}

vector<double> Network::get_w(int aLayer, int aNeuron) {
	return layers[aLayer]->get_w(aNeuron, 0);
}

int Network::size(int aLayer) {
	return layers[aLayer]->size();
}