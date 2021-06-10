#ifndef SAUTER_H
#define SAUTER_H

#include "utils.h"
#include "particle.h"

#include <random>

namespace sauter {

double distr(double cos_theta, double beta, double gamma){
    return (1- cos_theta*cos_theta)/std::pow(1-beta*cos_theta,4) 
            *(1+ 0.5 *gamma*(gamma-1)*(gamma-2)*(1-beta*cos_theta));
}

Double_t distr_root(Double_t *x, Double_t *par){
    return par[2]*(1- x[0]*x[0])/std::pow(1-par[0]*x[0],4) 
            *(1+ 0.5 *par[1]*(par[1]-1)*(par[1]-2)*(1-par[0]*x[0]));
}

Double_t distr_root_new(Double_t *x, Double_t *par){

    double beta = std::sqrt(par[0]*(par[0] + 2*m_e)) / (par[0] + m_e);
    double gamma = 1 + (par[0] / m_e);

    return par[1]*(1- x[0]*x[0])/std::pow(1-beta*x[0],4) 
            *(1+ 0.5 *gamma*(gamma-1)*(gamma-2)*(1-beta*x[0]));
}

double distr_max(double dx, double beta, double gamma){

    double max = 0;

    for (double cos_theta= -1.0; cos_theta < 1.0 ; cos_theta += dx){
        double sauter = distr(cos_theta, beta,gamma);
        if(max < sauter) max = sauter;
    }

    return max;
}

double sample_cos_theta(double beta, double gamma, std::mt19937 &mt){

    std::uniform_real_distribution<double> distr(-1.0,1.0);

    double uniform_distr_heigth = 1.2 * distr_max(0.0001,beta,gamma);
    std::uniform_real_distribution<double> distr_heigth(0.0,uniform_distr_heigth);

    double cos_theta = 0;
    double sample;

    do{

        cos_theta = distr(mt);
        sample = distr_heigth(mt);

    }while(sample > sauter::distr(cos_theta,beta,gamma));

    return cos_theta;
}

TVector3 sample_direction( TVector3 u1, double beta, double gamma, std::mt19937 &mt){

    TVector3 u2(0,0,1); // Sample u2 in the interaction frame (z parallel to u1)
    u2.SetTheta(std::acos(sample_cos_theta(beta, gamma, mt)));
    u2.SetPhi(random_phi(mt));

    // Transform u2 from the interaction frame to the coordinate frame
    TVector3 direction = u1.Unit();
    u2.RotateUz(direction);
    return u2;
}

std::vector<std::shared_ptr<Photon>> release_residual_energy( double U, TVector3 interaction_position, std::mt19937 &mt ){

    std::discrete_distribution<int> LShellElectronDistr{2,2,4};
    double LEnergies[3] = {0.01586, 0.01520, 0.01304};
    double E_gamma_Ka = LEnergies[LShellElectronDistr(mt)];
    double E_gamma_2 =  U - E_gamma_Ka;

    std::vector< std::shared_ptr<Photon> > Photons;
    Photons.push_back(std::make_shared<Photon>( E_gamma_Ka, interaction_position, random_unit_direction(mt)));
    Photons.push_back(std::make_shared<Photon>( E_gamma_2 , interaction_position, random_unit_direction(mt)));
    return Photons;
}

std::vector<std::shared_ptr<Particle>> photoelectric(  std::shared_ptr<Photon> gamma_in, double U, std::mt19937 &mt ){

    //Sample the photoelectric effect of a photon on lead

    //calculate step length based on the total cross section

    std::uniform_real_distribution<double> distr(0.0,1.0);

    double rho_Pb = 11.34; // g/cm3
    double N_A_A = 0.0029; // (cm2/g) / (cm^2/atom) * 10-24
    double sigma_E_tot = 2.37e1; // b / Atom (PLACEHOLDER VALUE FOR E_gamma = 1 MeV!)

    double mu_E = rho_Pb * N_A_A * sigma_E_tot; // cm-1

    double s = -1.0 / mu_E *std::log(distr(mt)); //cm

    //Sample particles in final state

    TVector3 interaction_position = gamma_in->getPosition() + s * gamma_in->getDirection();
    std::vector<std::shared_ptr<Particle>> particles;
    double E_e = gamma_in->getEnergy() - U;

    double beta = std::sqrt(E_e*(E_e + 2*m_e)) / (E_e + m_e);
    double gamma = 1 + (E_e / m_e);

    particles.push_back( std::make_shared<Electron>(E_e, interaction_position, sample_direction(gamma_in->getDirection(), beta, gamma, mt) ) );

    std::vector<std::shared_ptr<Photon>> photons = release_residual_energy(U, interaction_position, mt);
    particles.push_back(  photons[0] );
    particles.push_back(  photons[1] );
    
    return particles;
}

}



#endif
