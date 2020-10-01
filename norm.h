#ifndef NORM_H
#define NORM_H

#include <vector>
#include <iostream>	
#include "layer.h"

using namespace std;

class Norm : public Layer {
private:
	int del;
public:
	Norm(int aDel);
	virtual vector<double> process(const vector<double> aInp);
	virtual vector<double> correct(const vector<double> aInp);
	virtual int size() const;
};


#endif // !NORM_H

