/*
 * File:   Genetic.cpp
 * Author: oblivion
 *
 * Created on November 1, 2012, 12:12 AM
 */
#include "Genetic.h"
#include <glog/logging.h>

Genetic::Genetic(unsigned int nStrains)
{
    DLOG(INFO) << "Creating " << nStrains << " genetic strains.";
    for (unsigned int i = 0; i < nStrains; i++)
    {
        this->strains.push_back(NNet(2, 1, 4, 1));
    }
    DLOG(INFO) << "Creating fitness array.";
    for (unsigned int i = 0; i < nStrains; i++)
    {
        this->fitness.push_back(0.0);
    }
    this->crossover_rate = 0.1;
    this->mutation_rate = 0.01;
}

void Genetic::fitness(void)
{
    
}

void Genetic::evolve(vector<double> &inputs, vector<double> &outputs)
{
    DLOG(INFO) << "Evolving strains.";
    DLOG(INFO) << "Updating trains:";
    for (unsigned int i = 0; i < this->strains.size(); i++)
    {
        DLOG(INFO) << " " << i;
        //Set input value in each strain
        for (unsigned int j = 0; j < inputs.size(); j++)
        {
            this->strains[i].inputs[j].inputs[0] = inputs[j];
        }
        this->strains[i].update();
    }
    DLOG(INFO) << "Calculating scores:";
    for (unsigned int i = 0; i < this->strains.size(); i++)
    {
        DLOG(INFO) << " " << i;
        //Set input value in each strain
        for (unsigned int j = 0; j < inputs.size(); j++)
        {
            this->strains[i].inputs[j].inputs[0] = inputs[j];
        }
        this->strains[i].update();
    }
}

Genetic::~Genetic()
{
}
