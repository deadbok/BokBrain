/*
 * Neuron.h
 *
 *  Created on: Oct 16, 2012
 *      Author: oblivion
 */

#ifndef NEURON_H_
#define NEURON_H_

#include <ostream>
#include <vector>

using namespace std;

class Neuron
{
public:
    //Sizes
    unsigned int nInputs;


    vector<double> inputs;
    vector<double> weights;
    double output;

    Neuron(unsigned int nInputs);
    virtual ~Neuron();
};

ostream& operator<<(ostream& ost, const Neuron& neuron);

#endif /* NEURON_H_ */
