#include "utils.h"

#include "my_random.h"

#include <iostream>

int main(){

    uint32_t seed = 987654321;
    uint32_t iterator = 663608941;

    NaiveIterator *n = new NaiveIterator(seed, iterator);

    //for (size_t i = 0; i<10; i++) std::cout << random_double(n) << " " << std::endl ;

    TH1D *h1 = new TH1D("h1", "Iterator distribution", 100, 0, 1);

    for (size_t i = 0; i < n->max ; i++) h1->Fill( random_double(n) );

    TFile f("histo.root", "new");
	h1->Write();

}