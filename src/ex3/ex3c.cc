#include "utils.h"
#include "point.h"

#include <random>
#include <iostream>

double sample_pi(int N){

    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> distr(0.0,1.0);

    int inside = 0;
    int tot = 0;

    for(size_t i = 0; i<N; i++){
        Point p = rand_in_unit_square(distr, mt);
        if( (p.x*p.x + p.y*p.y) < 1.0) inside++; 
        tot ++;
    }

    return 4.0 * (double) inside / (double)tot;
}

int main(){

    int N = 100;

    TH1D *h = new TH1D("h", "N=100;#pi - #pi_{est};Counts", 50, -1.0, 1.0);

    for(size_t i = 0; i<1000; i++) h->Fill(M_PI - sample_pi(N));

    h->Fit("gaus");

    TCanvas *c = new TCanvas();
    //gStyle->SetOptStat(0);
    h->Draw();
    c->Print("hist_pi.pdf");



}