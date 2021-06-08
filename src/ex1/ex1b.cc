#include "utils.h"

#include "my_random.h"

#include <iostream>
#include <TApplication.h>

int main(Int_t argc, Char_t** argv){

     TApplication theApp("App", &argc, argv);

    uint32_t seed = 987654321;
    uint32_t iterator = 663608941;

    NaiveIterator *n = new NaiveIterator(seed, iterator);

    //for (size_t i = 0; i<10; i++) std::cout << random_double(n) << " " << std::endl ;

    //std::random_device rd;
    //std::mt19937 mt(rd());

    //std::uniform_real_distribution<double> distr(0.0,1.0);

    TH1D *h1 = new TH1D("h1", "", 100, 0, 1 );

    std::cout << "Filling histogram ... " << std::endl;

    for (size_t i = 0; i < 1000000 ; i++) h1->Fill( random_double(n) );
    //for (size_t i = 0; i < 1000000 ; i++) h1->Fill( distr(mt) );

    TF1 *f1 = new TF1(""," (1000000.0 / 100.0) ", 0, 1 );

	std::cout << "Chisquare is : " << h1->Chisquare(f1) << std::endl;

    std::cout << "Saving to file ... " << std::endl;

    TFile f("histo.root", "RECREATE");

	h1->Write();
	f1->Write();

    TCanvas *c = new TCanvas();
    gStyle->SetOptStat(0);
    h1->Draw();
    f1->Draw("SAME");
    theApp.Run();
    //c->Print("hist.pdf");
    return 0;

}