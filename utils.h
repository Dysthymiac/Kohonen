#ifndef UTILS_H
#define UTILS_H

#include <cmath>
#include <vector>

class Utils
{
public:
    static double sqr(double x)
    {
        return x * x;
    }


    static double distSqr(double x1, double y1, double x2, double y2)
    {
        return sqr(x1-x2) + sqr(y1-y2);
    }

    static double dist(double x1, double y1, double x2, double y2)
    {
        return sqrt(distSqr(x1, y1, x2, y2));
    }

    static double distSqr(const std::vector<double>& v1, const std::vector<double>& v2)
    {
        if(v1.size() != v2.size())
            return -1;
        double result = 0;
        for(size_t i = 0; i < v1.size(); ++i)
            result += sqr(v1[i]-v2[i]);
        return result;
    }

    static double dist(const std::vector<double>& v1, const std::vector<double>& v2)
    {
        return sqrt(distSqr(v1, v2));
    }
};

#endif // UTILS_H
