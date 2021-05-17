#ifndef POINT_H
#define POINT_H

#include "utils.h"

#include <random>

struct Point{
    double x;
    double y;
    Point(double x, double y) : x(x), y(y) {}
};

Point rand_in_unit_square(std::uniform_real_distribution<double> &distr, std::mt19937 &mt){
    double x,y;
    x = -1.0 + 2.0 * distr(mt);
    y = -1.0 + 2.0 * distr(mt);
    return Point(x,y);
}

#endif