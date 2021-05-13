#include "utils.h"

#include "my_random.h"

#include <iostream>

int main(){

    uint32_t seed = 987654321;
    uint32_t iterator = 663608941;

    NaiveIterator *n = new NaiveIterator(seed, iterator);

    //for (size_t i = 0; i<10; i++) std::cout << random_double(n) << " " << std::endl ;

    TH1D *h1 = new TH1D("h1", "Iterator distribution", 100, 0, 1 );

    std::cout << "Filling histogram ... " << std::endl;

    for (size_t i = 0; i < 1000000 ; i++) h1->Fill( random_double(n) );

    TF1 *f1 = new TF1("Flat distribution"," (1000000.0 / 100.0) ", 0, 1 );

	std::cout << "Chisquare is : " << h1->Chisquare(f1) << std::endl;

    std::cout << "Saving to file ... " << std::endl;

    TFile f("histo1000000.root", "RECREATE");

	h1->Write();
	f1->Write();

}