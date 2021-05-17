#ifndef UTILS_H
#define UTILS_H

//Common headers

#include <cmath>
#include <functional>
#include <iomanip>
#include <vector>
#include <TGraph.h>
#include <TH1D.h>
#include <TF1.h>
#include <TFile.h>
#include <TCanvas.h>
#include <TStyle.h>
#include <TEllipse.h>

//Usings

//Consts

const double pi = 3.1415926535897932385;

//Utility functions

inline double degrees_to_radians(double degrees){
	return degrees * pi / 180.0;
}

template <typename T>
std::vector<T> linspace(T a, T b, size_t N) {
    T h = (b - a) / static_cast<T>(N-1);
    std::vector<T> xs(N);
    typename std::vector<T>::iterator x;
    T val;
    for (x = xs.begin(), val = a; x != xs.end(); ++x, val += h)
        *x = val;
    return xs;
}
 
#endif