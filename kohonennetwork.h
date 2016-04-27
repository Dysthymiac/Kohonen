#ifndef KOHONENNETWORK_H
#define KOHONENNETWORK_H

#include <vector>
#include <cstdlib>
#include "utils.h"
#include <algorithm>

class KohonenNetwork
{
    std::vector<std::vector<std::vector< double> > > weights;

public:

    KohonenNetwork(size_t rows = 1, size_t cols = 1, size_t input = 1);

    inline size_t rows() { return weights.size(); }

    inline size_t cols()
    {
        if(rows() > 0)
            return weights[0].size();
        else
            return 0;
    }

    inline size_t input()
    {
        if(cols() > 0)
            return weights[0][0].size();
        else
            return 0;
    }

    void initWeights();

    void initWeightsGrad();

    inline std::vector<std::vector< double> > operator[](size_t i) const
    {
        return weights[i];
    }

    inline std::vector<std::vector< double> >& operator[](size_t i)
    {
        return weights[i];
    }

    void learn(const std::vector<std::vector<double> >& dataSet, int iterations, double learningRate);

    void learnStep(int step, const std::vector<double>& data, int iterations, double learningRate);

};

#endif // KOHONENNETWORK_H
