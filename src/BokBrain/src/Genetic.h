/*
 * File:   Genetic.h
 * Author: oblivion
 *
 * Created on November 1, 2012, 12:12 AM
 */

#ifndef GENETIC_H
#define	GENETIC_H

#include <vector>
#include "NNet.h"

using namespace std;

class Genetic
{
public:
    NNet nNet;
    vector<vector<double> > RNA;
    vector<double> fitnesses;
    vector<vector<double> > outputs;
    
    unsigned int nStrains;
    double crossover_rate;
    double mutation_rate;

    Genetic(unsigned int nStrains = 0);
    void fitness(vector<double> &result);
    void evolve(vector<double> &inputs, vector<double> &outputs);
    virtual ~Genetic();
};

#endif	/* GENETIC_H */

