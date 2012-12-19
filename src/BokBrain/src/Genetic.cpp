/*
 * File:   Genetic.cpp
 * Author: oblivion
 *
 * Created on November 1, 2012, 12:12 AM
 */
#include "Genetic.h"
#include <stdexcept>
#include <glog/logging.h>

Genetic::Genetic(unsigned int nStrains)
{
    this->nStrains = nStrains;
    this->crossover_rate = 0.1;
    this->mutation_rate = 0.01;
}

void Genetic::fitness(vector<double> &result)
{
    DLOG(INFO) << "Calculating fitness:";
    this->fitnesses.clear();
    for (unsigned int i = 0; i < this->nStrains; i++)
    {
        double sum = 0;
        //Run through the outputs
        for (unsigned int j = 0; i < this->outputs[i].size(); j++)
        {
            sum += result[j] - this->outputs[i][j];
        }
        sum /= (double) result.size();
        this->fitnesses.push_back(sum);
        DLOG(INFO) << " " << i << ": " << sum;
    }
}

void Genetic::evolve(vector<double> &inputs, vector<double> &outputs)
{
    DLOG(INFO) << "Evolving strains.";
    DLOG(INFO) << "Processing strains:";
    for (unsigned int i = 0; i < this->nStrains; i++)
    {
        DLOG(INFO) << " " << i;
        this->outputs.clear();
        //Restore the net
        this->nNet.setWeights(RNA[i]);
        
        //Check for correct input data
        if (inputs.size() != nNet.inputs.size())
        {
            throw std::length_error("Input vector is the wrong length.");
        }
        //Set input value in each strain
        for (unsigned int j = 0; j < inputs.size(); j++)
        {
            
            this->nNet.inputs[j].inputs[0] = inputs[j];
        }
        this->nNet.update();
        
        vector<double> output;
        for (unsigned int i = 0; i < this->outputs.size(); i++)
        {
            output.push_back(this->nNet.outputs[i].output);
        }
        this->outputs.push_back(output);
        
    }
    DLOG(INFO) << "Calculating scores:";
    this->fitness(outputs);
}

Genetic::~Genetic()
{
}
