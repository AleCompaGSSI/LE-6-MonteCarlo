#include "utils.h"

#include "timer.h"

#include <random>
#include <iostream>

double inversion(std::uniform_real_distribution<double> &distr, std::mt19937 mt){
    Timer timer;
    double x,y;
    double sum = 0;
    for( size_t i = 0; i<100000; i++){
        double xi1 = distr(mt);
        double xi2 = distr(mt);
        x = std::sqrt(xi1)*std::cos(2*M_PI*xi2);
        y = std::sqrt(xi1)*std::sin(2*M_PI*xi2);
        sum += x + y;
    }
    return sum;
}

double rejection(std::uniform_real_distribution<double> &distr, std::mt19937 &mt){
    Timer timer;
    double x,y;
    double sum = 0;
    for( size_t i = 0; i<100000; i++){
        while(true){
            x = -1.0 + 2.0 * distr(mt);
            y = -1.0 + 2.0 * distr(mt);
            if((x*x + y*y) < 1.0) break;
        }
        sum += x + y;
    }
    return sum;
}

int main(){

    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> distr(0.0,1.0);
    //mt.seed(2002);
    std::cout << "Inversion! ";
    std::cout << inversion(distr, mt) << std::endl;
    std::cout << "Rejection! ";
    std::cout << rejection(distr, mt) << std::endl;





}