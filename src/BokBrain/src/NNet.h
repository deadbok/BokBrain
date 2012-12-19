/*
 * NNet.h
 *
 *  Created on: Oct 12, 2012
 *      Author: oblivion
 */

#ifndef NNET_H_
#define NNET_H_

#include <vector>
#include "Neuron.h"

using namespace std;

class NNet
{
public:
    //Neurons
    vector<Neuron> inputs;
    vector<vector<Neuron> > hiddens;
    vector<Neuron> outputs;

    NNet(void);
    NNet(unsigned int nInputs, unsigned int nHidden, unsigned int hiddenNeurons, unsigned int nOutputs);
    double activation(double in);
    unsigned int updateLayer(vector<Neuron> &layer);
    void feedForward(vector<Neuron> &source, vector<Neuron> &target);
    unsigned int update(void);
    vector<double> getWeights(void);
    void setWeights(vector<double> &weights);
    virtual ~NNet();
};

#endif /* NNET_H_ */
