#include <iostream>
#include <ctime>
#include "gui.h"
#include "layer.h"
#include "neyralNetwork.h"
#include "norm.h"
#include "outputLayer.h"
#include "perceptron.h"
#include "percLayer.h"

using namespace std;

int main()
{
	vector<vector<double>> inputs = {};
	srand(time(0));
	for (int i = 0; i < 1000; i++) {
		inputs.push_back({0.25+(rand()%1000)/2000.,0.25 + (rand() % 1000) / 2000. });
	}
	int counter = 0;
	Gui g(1000, 1000, "F");
	Network net({ Network::LayerType::PERC,Network::LayerType::OUTPUTLAYER }, 2, 2, 100, 1, 0.3, 0, 200, 0.0001, 1.);
	while (g.isOpen()) {
		for (int i = 0; i < inputs.size(); i++) {
			counter++;
			net.process(inputs[i]);
			net.correct();
			vector<vector<double>> f(0);
			for (int j = 0; j < net.size(0); j++) {
				f.push_back(net.get_w(0,j));
			}
			if (counter % 2 == 0) {
				g.clear();
				g.matrix_for_maps(inputs, 0);
				g.matrix_for_maps(f, 1);
				g.render();
				if (g.evnt() == Gui::EventType::CLOSE) {
					return 0;
				}
			}
		}
		/*g.clear();
		g.matrix_for_maps(inputs,0);
		g.render();
		if (g.evnt() == Gui::EventType::CLOSE) {
			return 0;
		}*/
	}
	return 0;
}
