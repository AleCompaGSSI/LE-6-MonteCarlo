#include "utils.h"

#include "my_random.h"

#include <iostream>

int main(){

    uint32_t seed = 987654321;
    uint32_t iterator = 663608941;

    NaiveIterator *n = new NaiveIterator(seed, iterator);

    int length = 0;

    while ( n->iterate() % seed != 0 ) lenght++;

    std::cout << "The length is: " << length << std::endl;

    //for (size_t i = 0; i<10; i++) std::cout << random_double(n) << " " << std::endl ;

}