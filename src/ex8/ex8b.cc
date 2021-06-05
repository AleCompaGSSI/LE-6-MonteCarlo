#include "utils.h"
#include "sauter.h"

#include <iostream>
#include <random>

int main(){

    std::random_device rd;
    std::mt19937 mt(rd());

    double E = 1.0; //MeV
    const double U = 0.088; //MeV

    std::shared_ptr<Photon> gamma_in = std::make_shared<Photon>( E, TVector3(0,0,0), TVector3(1,1,1) );

    std::cout << "Initial state :" <<std::endl;
    std::cout << *gamma_in <<std::endl;

    std::vector< std::shared_ptr<Particle> > final_state = sauter::photoelectric(gamma_in, U, mt);

    std::cout << "Final state :" << std::endl;
    std::cout << *final_state[0] << std::endl;
    std::cout << *final_state[1] << std::endl;
    std::cout << *final_state[2] << std::endl;

}