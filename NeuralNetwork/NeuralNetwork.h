#pragma once
#include "Matrix.h"
#include <cstdlib>

class SimpleNeuralNetwork
{
    public:
        std::vector<uint32_t> _topology;
        std::vector<Matrix> _weightsMatrices;
        std::vector<Matrix> _valuesMatrices;
        std::vector<Matrix> _biasMatrices;
        float _learningRate;

    public:
        SimpleNeuralNetwork(std::vector<uint32_t> topology, float learningRate = 0.1f)
            :_topology(topology),
            _weightsMatrices({}),
            _valuesMatrices({}),
            _biasMatrices({}),
            _learningRate(learningRate)
        
        {
            for(uint32_t i = 0; i < topology.size() - 1; i++)
            {
                Matrix weightsMatrix(topology[i + 1], topology[i]);
                
            }
        }
};

