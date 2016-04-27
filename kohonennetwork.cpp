#include "kohonennetwork.h"

#include <QDebug>

KohonenNetwork::KohonenNetwork(size_t rows, size_t cols, size_t input):weights(rows,std::vector<std::vector<double> >(cols, std::vector<double>(input, 0)))
{

}

void KohonenNetwork::initWeights()
{
    for(size_t y = 0; y < rows(); ++y)
        for(size_t x = 0; x < cols(); ++x)
            for(size_t i = 0; i < input(); ++i)
                weights[y][x][i] = (double)rand() / RAND_MAX;
}

void KohonenNetwork::initWeightsGrad()
{
    for(size_t y = 0; y < rows(); ++y)
        for(size_t x = 0; x < cols(); ++x)
            for(size_t i = 0; i < input(); ++i)
                weights[y][x][i] = sqrt(Utils::distSqr(x,y,0,0)/Utils::distSqr(rows(),cols(),0,0));
}


void KohonenNetwork::learn(const std::vector<std::vector<double> > &dataSet, int iterations, double learningRate)
{
    for(int i = 1; i <= iterations; ++i)
        learnStep(i, dataSet[rand() % dataSet.size()], iterations, learningRate);


}

void KohonenNetwork::learnStep(int step, const std::vector<double> &data, int iterations, double learningRate)
{
    double mapRadius = std::max(cols(), rows()) / 2.0;
    double timeConstant = iterations/log(mapRadius);
    double lr = learningRate;

    double dist = Utils::distSqr(weights[0][0], data);
    double bestX = 0;
    double bestY = 0;
    for(size_t y = 0; y < rows(); ++y)
        for(size_t x = 0; x < cols(); ++x)
        {
            double c = Utils::distSqr(weights[y][x], data);
            if(c < dist)
            {
                dist = c;
                bestX = x;
                bestY = y;
            }
        }

    double neighbourhoodRadiusSqr = Utils::sqr(mapRadius * exp(-(double)step/timeConstant));
    bool flag = rand() % 2;
    for(size_t y = 0; y < rows(); ++y)
        for(size_t x = 0; x < cols(); ++x)
        {
            double distSqr = Utils::distSqr(x,y, bestX, bestY);
            if (distSqr < neighbourhoodRadiusSqr)
            {
                //influence = exp(-(distSqr) / (2*neighbourhoodRadiusSqr));
                double influence;
                if(flag)
                    influence = 10 - 10*Utils::sqr((distSqr) / (2*neighbourhoodRadiusSqr));
                else
                    influence = 10*Utils::sqr((distSqr) / (2*neighbourhoodRadiusSqr));
                //double influence = 10*((distSqr) / (2*neighbourhoodRadiusSqr));
                for(size_t j = 0; j < input(); ++j)
                    weights[y][x][j] += influence * lr * (data[j]-weights[y][x][j]);
            }
        }

    lr = learningRate * exp(-(double)step/iterations);

}

