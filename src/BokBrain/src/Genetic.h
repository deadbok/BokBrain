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
    vector<NNet> strains;
    vector<double> fitness;
    double crossover_rate;
    double mutation_rate;

    Genetic(unsigned int nStrains);
    void fitness(void);
    void evolve(vector<double> &inputs, vector<double> &outputs);
    virtual ~Genetic();
};

#endif	/* GENETIC_H */

