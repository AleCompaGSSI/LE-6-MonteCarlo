#include "utils.h"
#include "sauter.h"

#include <iostream>
#include <random>

int main(){


    std::random_device rd;
    std::mt19937 mt(rd());

    double E = 1.0; //MeV
    const double U = 0.088; //MeV

    std::shared_ptr<Photon> gamma_in = std::make_shared<Photon>( E, TVector3(0,0,0), TVector3(0,1,0) );

    TH1D *h = new TH1D("h", "Electron distr, N=50000, direction = (0,1,0);cos(#theta);Counts", 500, -1.0, 1.0);

    int N = 50000;
    
    for(size_t i = 0; i < N; i++) {

        std::vector< std::shared_ptr<Particle> > final_state = sauter::photoelectric(gamma_in, U, mt);
        h->Fill(std::cos(final_state[0]->getDirection().Theta()));

    };


    TCanvas *c = new TCanvas();
    gStyle->SetOptStat(0);
    h->Draw();
    c->SetLogy();
    c->Print("hist_sauter_shift.pdf");



}