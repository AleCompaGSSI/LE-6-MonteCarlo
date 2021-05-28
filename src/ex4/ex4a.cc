#include "utils.h"
#include "risiko.h"

#include <random>
#include <iostream>

int main(){

    int N = 100000;
    int tot_won;

    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> distr(1,6);

    for ( size_t i = 0; i < N; i++) tot_won += risiko::throw_attack( distr, mt, 3, 3 );

    std::cout << "Average won armies: "         << (double) tot_won / N         << std::endl;
    std::cout << "Average won armies per die: " << (double) tot_won / ( 3 * N ) << std::endl;

}