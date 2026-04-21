#include <iostream>
#include <functional>
#include <utility>
#include <cmath>
#include <vector>


enum sumType {RIGHT, LEFT, MID, TRAP};
double estimateArea(std::function<double(double)> func, 
                               std::pair<int, int> interval, 
                               int numSubdivisions, sumType s) {
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
    


int main(void) {

    double areaUnder = estimateArea([](double x) -> double { return std::sqrt(9-std::pow(x, 2));}, {-3, 3}, 100000, MID);

    printf("Area: %f", areaUnder);
}