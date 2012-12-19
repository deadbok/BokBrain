/*
 * NNet.cpp
 *
 *  Created on: Oct 12, 2012
 *      Author: oblivion
 */
#include <cmath>
#include <stdexcept>
#include <glog/logging.h>
#include <bits/stl_vector.h>
#include "NNet.h"

NNet::NNet(void)
{
    DLOG(INFO) << "NNet constructor.";
}

NNet::NNet(unsigned int nInputs, unsigned int nHidden, unsigned int hiddenNeurons, unsigned int nOutputs)
{
    //Initialise the input and layer
    DLOG(INFO) << "Creating input layer.";
    for (unsigned int i = 0; i < nInputs; i++)
    {
        //One input
        this->inputs.push_back(Neuron(1));
    }

    //Initialise the hidden layers
    DLOG(INFO) << "Creating hidden layer.";
    for (unsigned int i = 0; i < nHidden; i++)
    {
        DLOG(INFO) << "Creating hidden layer " << i << ".";
        vector<Neuron> layer;
        for (unsigned int j = 0; j < hiddenNeurons; j++)
        {
            if (i == 0)
            {
                //First hidden layer has only enough inputs to connect to the input layer
                layer.push_back(Neuron(nInputs));
            }
            else
            {
                //Same amount of inputs as previous outputs
                layer.push_back(Neuron(hiddenNeurons));
            }
        }
        this->hiddens.push_back(layer);
    }

    //Initialize the output layer
    DLOG(INFO) << "Creating output layer.";
    for (unsigned int i = 0; i < nOutputs; i++)
    {
        //Same amount of inputs as nets
        this->outputs.push_back(Neuron(hiddenNeurons));
    }
}

double NNet::activation(double x)
{
    //Sigmoid
    return (1.0 / (1.0 + exp(-x)));
}

unsigned int NNet::updateLayer(vector<Neuron> &layer)
{
    DLOG(INFO) << "Updating layer.";
    //Each neuron
    for (std::vector<Neuron>::size_type i = 0; i < layer.size(); i++)
    {
        //Each input
        std::vector<double>::size_type j = 0;
        for (; j < layer[i].inputs.size(); j++)
        {
            //Weighted sum
            layer[i].output += layer[i].weights[j] * layer[i].inputs[j];
        }
        //Threshold
        layer[i].output -= layer[i].weights[j + 1];
        //Activation function
        layer[i].output = this->activation(layer[i].output);
    }
}

void NNet::feedForward(vector<Neuron> &source, vector<Neuron> &target)
{
    //Copy output to the input of next layer
    DLOG(INFO) << "Forwarding output.";
    for (std::vector<Neuron>::size_type i = 0; i < source.size(); i++)
    {
        for (std::vector<Neuron>::size_type j = 0; j < target.size(); j++)
        {
            target[j].inputs[i] = source[i].output;
        }
    }
}

unsigned int NNet::update(void)
{

    DLOG(INFO) << "Updating network.";
    DLOG(INFO) << "Input layer.";
    this->updateLayer(this->inputs);
    this->feedForward(this->inputs, this->hiddens[0]);

    DLOG(INFO) << "Hidden layers:";
    std::vector<vector<Neuron> >::size_type i = 0;
    for (; i < (this->hiddens.size() - 1); i++)
    {
        DLOG(INFO) << " " << i;
        this->updateLayer(this->hiddens[i]);
    }

    DLOG(INFO) << " " << i;
    this->updateLayer(this->hiddens[i]);
    this->feedForward(this->hiddens[i], this->outputs);

    DLOG(INFO) << "Output layer.";
    //Each neuron
    for (std::vector<Neuron>::size_type i = 0; i < this->outputs.size(); i++)
    {
        //Each input
        std::vector<double>::size_type j = 0;
        for (; j < this->outputs[i].inputs.size(); j++)
        {
            //Weighted sum
            this->outputs[i].output += this->outputs[i].weights[j] * this->outputs[i].inputs[j];
        }
        //Threshold
        this->outputs[i].output -= this->outputs[i].weights[j + 1];
        //Activation function
        this->outputs[i].output = this->activation(this->outputs[i].output);
    }

}

vector<double> NNet::getWeights(void)
{
    DLOG(INFO) << "Getting weights.";
    vector<double> ret;

    //Assemble the weights from the input layer
    for (unsigned int i = 0; i < this->inputs.size(); i++)
    {
        ret.insert(ret.end(), this->inputs[i].weights.begin(), this->inputs[i].weights.end());
    }
    //Assemble the weights from the hidden layers
    for (unsigned int j = 0; j < this->hiddens.size(); j++)
    {
        for (unsigned int i = 0; i < this->hiddens[j].size(); i++)
        {
            ret.insert(ret.end(), this->hiddens[j][i].weights.begin(), this->hiddens[j][i].weights.end());
        }
    }

    //Assemble the weights from the output layer
    for (unsigned int i = 0; i < this->outputs.size(); i++)
    {
        ret.insert(ret.end(), this->outputs[i].weights.begin(), this->outputs[i].weights.end());
    }
    return(ret);
}

void NNet::setWeights(vector<double> &weights)
{
    DLOG(INFO) << "Setting weights.";    
    unsigned int nWeights = 0;
    
    DLOG(INFO) << "Checking for matching data size.";
    //Find the number of weights in the input layer
    for (unsigned int i = 0; this->inputs.size(); i++)
    {
        nWeights += this->inputs[i].weights.size();
    }

    //Find the number of weights for all hidden layers
    //For each layer
    for (unsigned int i = 0; this->hiddens.size(); i++)
    {
        //For each neuron
        for (unsigned int j = 0; this->hiddens[i].size(); j++)
        {
            nWeights += this->hiddens[i][j].weights.size();
        }
    }
    
    //Find the number of weights in the output layer
    for (unsigned int i = 0; this->outputs.size(); i++)
    {
        nWeights += this->outputs[i].weights.size();
    }

    //Check if the number of weights corresponds with the input
    if (nWeights != weights.size())
    {
        DLOG(ERROR) << "Size of weights does not match size of the net.";
        throw std::length_error("Size of weights does not match size of the net.");
    }
    
    
    DLOG(INFO) << "Assign weights.";
    //Keep an index into the weights
    unsigned int iWeights = 0;

    //Assign weights to the input layer    
    for (unsigned int i = 0; this->inputs.size(); i++)
    {
        unsigned int next = iWeights + this->inputs[i].weights.size();
        this->inputs[i].weights.assign(weights.begin() + iWeights, weights.begin() + (next-1));
        iWeights = next;
    }

    //Assign weights to the hidden layer(s)
    //Layers    
    for (unsigned int i = 0; this->hiddens.size(); i++)
    {
        //Neurons
        for (unsigned int j = 0; this->hiddens[i].size(); j++)
        {
            unsigned int next = iWeights + this->hiddens[i][j].weights.size();
            this->hiddens[i][j].weights.assign(weights.begin() + iWeights, weights.begin() + (next-1));
            iWeights = next;
        }
    }

}

NNet::~NNet()
{
    // TODO Auto-generated destructor stub
}

