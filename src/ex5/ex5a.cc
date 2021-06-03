#include "utils.h"

#include <random>
#include <iostream>

double sample_integral( int n, int histories, std::uniform_real_distribution<double> &distr, std::mt19937 &mt){

    int inside = 0;

    for(size_t i = 0; i < histories; i++){
        double x = distr(mt);
        if (distr(mt) < std::pow(x,n)) inside++;
    }

    double integral = ((double) inside) / ((double) histories );
    double theoretical = 1.0 / ((double) n + 1.0 );

    //std::cout << std::setprecision(4) << integral << "\t" ;
    //std::cout << theoretical  << "\t";
    //std::cout << std::abs( integral - theoretical ) << std::endl;
    return  ( integral - theoretical );

}


int main(){

    const int N = 1;
    const int histories = 1000;
    const int samples = 1000;

    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> distr(0.0,1.0);

    TH1D *h = new TH1D("h", "N=1;#MC - #th;Counts", 50, -0.1, 0.1);

    for(size_t i = 0; i < samples ; i++) h->Fill(sample_integral( N, histories, distr, mt ));

    h->Fit("gaus");

    TCanvas *c = new TCanvas();
    //gStyle->SetOptStat(0);
    h->Draw();
    c->Print("hist_integral.pdf");

}