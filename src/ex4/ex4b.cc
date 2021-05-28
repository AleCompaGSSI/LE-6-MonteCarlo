#include "utils.h"
#include "risiko.h"

#include <iostream>

int main(){

    int N = 10000;
    int armies = 12;
    int tot_won = 0;
    int tot_desirable_outcome = 0;

    TH1I *h = new TH1I("h", "Armies left after N_{a}=8 attack;Armies;Counts", 21, 0, 20);


    for(size_t i = 0; i < N; i++) {
        int left_armies = risiko::attack_kamchatka( armies, 3 );
        if ( left_armies > 0 ) tot_won++;
        if (left_armies > 5 ) tot_desirable_outcome++;
        h->Fill(left_armies);
        
        

    }

    std::cout << "Win rate with " << armies << " armies : " << (double) tot_won / N << std::endl;
    std::cout << "Prob. to end up with at least 6 armies left : " << (double) tot_desirable_outcome / N << std::endl;

    TCanvas *c = new TCanvas();
    gStyle->SetOptStat(0);
    h->Draw();
    c->Print("hist_risiko.pdf");

}