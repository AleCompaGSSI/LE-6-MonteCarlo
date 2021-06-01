#include "utils.h"

#include <random>
#include <iostream>

void sum_float(int N){
    float x = 0;
    for ( int i = 0; i < N; i++) x += 1.0 / (float) N ;
    std::cout <<"Float\t:"<< N << " " << x << " " << 1.0 / (float) N << std::endl;
  
}

void sum_double(int N){
    double x = 0;
    for ( int i = 0; i < N; i++) x += 1.0 / (double) N ;
    std::cout <<"Double\t:"<< N << " " << x << " " << 1.0 / (double) N << std::endl;  
}


int main(){


    sum_float(100);
    sum_float(1000);
    sum_float(10000);
    sum_float(100000);
    sum_float(1000000);
    sum_float(10000000);

    sum_double(10000);
    sum_double(100000);
    sum_double(1000000);
    sum_double(10000000);
    sum_double(100000000);
    sum_double(1000000000);


}