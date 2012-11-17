/*
 * Neuron.cpp
 *
 *  Created on: Oct 16, 2012
 *      Author: oblivion
 */

#include "Neuron.h"
#include <cstdlib>
#include <glog/logging.h>

Neuron::Neuron(unsigned int nInputs)
{
	DLOG(INFO) << "Creating a neuron with " << nInputs << " inputs.";
	//Sizes
	this->nInputs = nInputs;

	//Initialise inputs and weights
	for (std::vector<double>::size_type i = 0; i < nInputs; i++)
	{
		this->inputs.push_back(0.0);
		this->weights.push_back((double)std::rand() / RAND_MAX);
	}
         //Extra threshold weight
        this->weights.push_back((double)std::rand() / RAND_MAX);

	//Initialize output
	this->output = 0;
}

Neuron::~Neuron()
{
	// TODO Auto-generated destructor stub
}

ostream& operator<<(ostream& ost, const Neuron& neuron)
{
    ost << "Inputs: ";
    for (std::vector<double>::size_type i = 0; i < neuron.inputs.size(); i++)
    {
        ost<< neuron.inputs[i] << " ";
    }
    ost << endl << "weights: ";
    for (std::vector<double>::size_type i = 0; i < neuron.weights.size(); i++)
    {
        ost<< neuron.weights[i] << " ";
    }
    ost << endl << "Output: " << neuron.output << endl;
    return ost;
}

