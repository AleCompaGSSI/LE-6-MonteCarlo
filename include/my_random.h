#ifndef MY_RAND_H
#define MY_RAND_H

#include "utils.h"


class MyRandomInt{

public:
	MyRandomInt( uint32_t s ): seed(s) {}

	virtual uint32_t iterate()  = 0;

public:
	uint32_t seed;
	uint32_t max ;

};

class NaiveIterator: public MyRandomInt{
public:
	NaiveIterator( uint32_t s, uint32_t i ): MyRandomInt(s), iterator(i)  { max = 4294967295; }

	virtual uint32_t iterate() override { seed = seed * iterator; return seed; }

private:
	uint32_t iterator;
};

double random_double( MyRandomInt *rnd ){
    // Returns a random real in [0,1).
    return (double)rnd->iterate() / ((double)rnd->max + 1.0);
}

double random_double( double min, double max, MyRandomInt *rnd ){
	return min + (max - min) * random_double( rnd );
}

#endif