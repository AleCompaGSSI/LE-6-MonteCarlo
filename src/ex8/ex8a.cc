#include "utils.h"
#include "sauter.h"

#include <iostream>
#include <random>

int main(){

    std::random_device rd;
    std::mt19937 mt(rd());

    double E = 1; //MeV
    const double U = 0.088; //MeV
    double E_e = E - U;

    double beta = std::sqrt(E_e*(E_e + 2*m_e)) / (E_e + m_e);
    double gamma = 1 + (E_e / m_e);

    std::cout <<"Beta :" << beta << ", Gamma :" << gamma << std::endl;

    TH1D *h = new TH1D("h", "Electron distr. N=5000, direction = (0,0,1);cos(#theta);Counts", 500, -1.0, 1.0);

    int N = 50000;
    
    for(size_t i = 0; i < N; i++) h->Fill(sauter::sample_cos_theta(beta,gamma, mt));

    TF1 *f1 = new TF1("f1", sauter::distr_root, -1.0, 1.0, 3);
    f1->SetParameters(0.9,2, 500000);
    h->Fit("f1");

    TCanvas *c = new TCanvas();
    gStyle->SetOptStat(0);
    h->Draw();
    f1->Draw("same");
    c->SetLogy();
    c->Print("hist_sauter.pdf");




}