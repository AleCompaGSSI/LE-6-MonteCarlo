#include "utils.h"
#include "risiko.h"

#include <iostream>

int main(){

    int N = 100;
    int armies = 10;
    int tot_won = 0;

    for(size_t i = 0; i < N; i++) {
        if ( risiko::attack_kamchatka( armies, 3 ) ) tot_won++;
    }

    std::cout << "Win rate with " << armies << " armies : " << (double) tot_won / N << std::endl;

}