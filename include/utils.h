#ifndef UTILS_H
#define UTILS_H

//Common headers

#include <cmath>
#include <functional>
#include <iomanip>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <random>
#include <memory>
#include <TGraph.h>
#include <TH1D.h>
#include <TH1I.h>
#include <TF1.h>
#include <TFile.h>
#include <TCanvas.h>
#include <TStyle.h>
#include <TEllipse.h>
#include <TVector3.h>

//Usings

//Consts

const double pi  = 3.1415926535897932385;
const double m_e = 0.510998950; //MeV

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

inline double random_theta(std::mt19937 &mt){
    std::uniform_real_distribution<double> distr(0.0, pi);
    return distr(mt);
}

inline double random_phi(std::mt19937 &mt){
    std::uniform_real_distribution<double> distr(0.0,2*pi);
    return distr(mt);
}

inline TVector3 random_unit_direction(std::mt19937 &mt){

    TVector3 v(0,0,1);
    v.SetTheta(random_theta(mt));
    v.SetPhi(random_phi(mt));

    return v;
}
 
#endif