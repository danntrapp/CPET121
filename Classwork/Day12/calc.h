#ifndef CALC_H
#define CALC_H
#include <cmath>
#include <vector>
#include <functional>


class Calc {
    public: 
    enum sumType {RIGHT, LEFT, MID};
    static double estimateArea(std::function<double(double)> func, 
                               std::pair<double, double> interval, 
                               int numSubdivisions, sumType s);
};
#endif