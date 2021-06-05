#ifndef PARTICLE_H
#define PARTICLE_H

#include "utils.h"

class Particle{

public:
    Particle( double E, TVector3 P, TVector3 D, double M  ): energy(E), position(P), direction(D), mass(M) {
        momentum = direction.Unit() * std::sqrt(energy*energy - mass*mass);
    }
    Particle( const Particle& ) = default;
    inline double getEnergy(){ return energy; }
    inline TVector3 getPosition(){ return position; }
    inline TVector3 getDirection(){ return direction; }
    
    virtual std::string name() const = 0;
    
    friend std::ostream& operator<<(std::ostream& stream, const Particle& particle){
        stream <<std::fixed <<std::setprecision(3) << particle.name() << "\t" << particle.energy 
                << ",\t" << particle.position.X()
                << ",\t" << particle.position.Y() 
                << ",\t" << particle.position.Z() 
                << ",\t" << particle.direction.X() 
                << ",\t" << particle.direction.Y() 
                << ",\t" << particle.direction.Z();
        return stream;
    };

private:
    double energy;
    double mass;
    TVector3 position;
    TVector3 direction;
    TVector3 momentum;

};

class Photon : public Particle{

public:
    Photon( double E, TVector3 P, TVector3 D): Particle(E, P, D, 0.0) {}
    Photon( const Photon& ) = default;
    //~Photon( ) {std::cout << this->name() << " deleted.. " << this->getEnergy() << std::endl;};
    virtual std::string name() const override { return "g";}

};

class Electron : public Particle{

public:
    Electron( double E, TVector3 P, TVector3 D): Particle(E, P, D, m_e) {}
    Electron( const Electron& ) = default;
    //~Electron() {std::cout << this->name() << " deleted.. "<< this->getEnergy()  << std::endl;};
    virtual std::string name() const override { return "e";}

};


#endif