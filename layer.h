#ifndef LAYER_H
#define LAYER_H
	
#include <vector>
using namespace std;

class Layer {
public:
	virtual vector<double> process(const vector<double> aInp) = 0;
	virtual vector<double> correct(const vector<double> aInp) = 0;

	virtual int size() const = 0;

	virtual vector<double> get_w(int num_of_perc, bool flag) {
		return {};
	}
};

#endif // !LAYER_H
