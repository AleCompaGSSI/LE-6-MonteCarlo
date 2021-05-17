#include "utils.h"

#include "timer.h"

#include <random>
#include <iostream>

void inversion(std::uniform_real_distribution<double> distr, std::mt19937 mt){
    Timer timer;
    double x,y;
    for( size_t i = 0; i<100000; i++){
        double xi1 = distr(mt);
        double xi2 = distr(mt);
        x = std::sqrt(xi1)*std::cos(2*M_PI*xi2);
        y = std::sqrt(xi1)*std::sin(2*M_PI*xi2);

    }
}

void rejection(std::uniform_real_distribution<double> distr, std::mt19937 mt){
    Timer timer;
    double x,y;
    for( size_t i = 0; i<100000; i++){
        do{
            x = -1.0 + 2.0 * distr(mt);
            y = -1.0 + 2.0 * distr(mt);
        } while ((x*x + y*y) < 1.0);
    }
}

int main(){

    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> distr(0.0,1.0);
    //mt.seed(2002);
    std::cout << "Inversion! ";
    inversion(distr, mt);
    std::cout << "Rejection! ";
    rejection(distr, mt);





}