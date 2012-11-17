/*
 ============================================================================
 Name        : BokBrain.c
 Author      : deadbok
 Version     :
 Copyright   : Copyright ? 2012 Martin Gr?nholdt,
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <glog/logging.h>
#include "NNet.h"
#include "Genetic.h"

int main(int argc, char* argv[])
{
    // Initialize Google's logging library.
    google::InitGoogleLogging(argv[0]);

    DLOG(INFO) << "BokBrain waking...";

    DLOG(INFO) << "Initializing random number generator.";
    srand(time(NULL));

    DLOG(INFO) << "Creating artificial neural network.";
    NNet net = NNet(2, 1, 4, 1);
    net.inputs[0].inputs[0] = 1;
    net.update();

    for (std::vector<Neuron>::size_type i = 0; i < net.outputs.size(); i++)
    {
        Neuron neuron = net.outputs[i];
        std::cout << neuron;
    }

    DLOG(INFO) << "Creating genetic strains.";
    Genetic brains = Genetic(10);
    
    return EXIT_SUCCESS;
}
