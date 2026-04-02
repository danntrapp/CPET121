#pragma once
#include "calc.h"
    double Calc::estimateArea(std::function<double(double)> func, 
                               std::pair<double, double> interval, 
                               int numSubdivisions, Calc::sumType s) {
        double a = interval.first;
        double b = interval.second;
        double dx = (b - a) / numSubdivisions;
        double sum = 0.0;
        
        switch(s) {
            case LEFT:
                for(int i = 0; i < numSubdivisions; i++) {
                    sum += func(a + i * dx);
                }
                break;
            case RIGHT:
                for(int i = 1; i <= numSubdivisions; i++) {
                    sum += func(a + i * dx);
                }
                break;
            case MID:
                for(int i = 0; i < numSubdivisions; i++) {
                    sum += func(a + (i + 0.5) * dx);
                }
                break;
        }
        return sum * dx;
    }
    