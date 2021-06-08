#include "utils.h"

#include <random>
#include <iostream>

template <typename T>
void sum( int N ){
    T x = 0;
    for ( int i = 0; i < N; i++) x += 1.0 / static_cast<T>( N );
    std::cout <<"\t" << " " <<std::setprecision(12)<< x - 1.0 << "\t" << 1.0 / static_cast<T>( N )<< " " << N << std::endl;  

}


int main(){

    std::cout << "Float : \n" ; sum<float >(10000); sum<float >(100000); sum<float >(1000000);
    std::cout << "Double : \n"; sum<double>(10000); sum<double>(100000); sum<double>(1000000);

}