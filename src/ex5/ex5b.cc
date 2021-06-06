#include "utils.h"

#include <random>
#include <iostream>

double sample_int_MC( int D, int histories ){

    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> distr(0.0,1.0);

    int inside = 0;

    for(size_t i = 0; i < histories; i++){

        double y = distr(mt);
        double prod = std::exp(-distr(mt));
        for(size_t i = 1; i < D; i++) prod *= std::exp(-distr(mt));

        if (y < prod) inside++;
    }

    double integral = ((double) inside) / ((double) histories );
    double theoretical = std::pow(1.0 - ( 1 / std::exp(1) ),D);

    return  std::abs( integral - theoretical );

}

double sample_int_midpoint( int D, int lines ){


    double integral = 0.0;
    double dx = 1.0 /(double) lines;

    for(double x = 0.0; x < 1.0; x+=dx) integral += std::exp(-(x+0.5*dx))*dx;

    integral = std::pow(integral,D); 
    double theoretical = std::pow(1.0 - ( 1 / std::exp(1) ),D);    
    return  std::abs( integral - theoretical );

}

int main(){

    const int D = 8;
    const int histories = 65536;
    const int lines     = 4;
    const int cells     = lines * D;

    double sample_MC        = sample_int_MC(D, histories);
    double sample_midpoint  = sample_int_midpoint(D, lines);

    std::cout << " D = " << D << " MC,       N_hist  = " << histories << " : " << sample_MC       << std::endl;
    std::cout << " D = " << D << " Midpoint, N_cells = " << cells     << " : " << sample_midpoint << std::endl;


}