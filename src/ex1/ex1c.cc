#include "utils.h"

#include "my_random.h"

#include <iostream>

void FindMINSTDPeriod ( uint32_t seed ){

    uint32_t m = 2147483647;
    //uint32_t m = 1048575;
    uint32_t a = 16807;

    MINSTD *rng1 = new MINSTD(seed, m, a);
    MINSTD *rng2 = new MINSTD(seed, m, a);

    //find the loop with the Floyd's tortoise and hare algorithm for cycle detection

    uint32_t n1 = 0;
    uint32_t n2 = 0;
    uint32_t iteration = 0;

    do{
        n1 = rng1->iterate();
        n1 = rng1->iterate();
        n2 = rng2->iterate();
        iteration ++;
    } while (n1 != n2);

    uint32_t mu = 0;

    MINSTD *rng3 = new MINSTD(seed, m, a);
    n2 = 0;

    do {
        n2 = rng3->iterate();
        n1 = rng1->iterate();
        mu++;
    } while (n1 != n2);

    uint32_t lam = 1;

    n1 = rng1->iterate();
    while ( n1 != n2 ){
        n1 = rng1->iterate();
        lam ++;
    }

    std::cout << "Seed : " << seed << " ";
    std::cout << "Exited! The total length is : "<< mu + lam << " " ;
    std::cout << "Loop size : " <<lam << std::endl;

    delete rng1;
    delete rng2;
    delete rng3;

}


int main(){

    FindMINSTDPeriod( 1 );
    FindMINSTDPeriod( 2 );
    FindMINSTDPeriod( 3 );
    FindMINSTDPeriod( 100046 );
    FindMINSTDPeriod( 20211305 );
    FindMINSTDPeriod( 24091996 );

}