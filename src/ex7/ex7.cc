#include "utils.h"

#include <random>
#include <iostream>

double exp_distr( double mu, std::uniform_real_distribution<double> &distr, std::mt19937 &mt){
    return - 1.0 / mu * std::log( distr(mt) );
}

int main(){


    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> distr(0.0,1.0);

    int N = 5000;

    const double mu1 = 1.0;
    const double mu2 = 2.0;

    TH1D *h = new TH1D("h", "Exponential Fit of min(#mu_{1},#mu_{2}) N=5000;min(#mu_{1},#mu_{2});Counts", 50, 0., 5.0);

    double s1 = exp_distr( mu1, distr, mt);
    double s2 = exp_distr( mu2, distr, mt);

    //std::cout << s1 <<" "<<s2<<std::endl;

    for(size_t i = 0; i < N; i++){

        s1 = exp_distr( mu1, distr, mt);
        s2 = exp_distr( mu2, distr, mt);

        //std::cout << s1 <<" "<<s2<<std::endl;

        if (s1 < s2) h->Fill(s1);
            else h->Fill(s2);
    }

    TF1 *f1 = new TF1("f1", "[1]*[0]*TMath::Exp(-[0]*x)");
    f1->SetParameters(4.0,5000);
    h->Fit("f1");


    TCanvas *c = new TCanvas();
    //gStyle->SetOptStat(0);
    h->Draw();
    f1->Draw("same");
    c->Print("hist_exp.pdf");


}