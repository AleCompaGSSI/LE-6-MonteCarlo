#include "utils.h"

#include <random>
#include <iostream>

int throw_attack( std::uniform_int_distribution<int> &distr, std::mt19937 &mt){

    std::vector<int> attack  = {distr(mt), distr(mt), distr(mt)};
    std::vector<int> defense = {distr(mt), distr(mt), distr(mt)};

    std::sort( attack.begin(),  attack.end()  );
    std::sort( defense.begin(), defense.end() );

    int won = 0;

    for ( size_t i = 0; i < 2; i++){
        if (attack[i] > defense[i]) won ++;
    }

    return won;
}

int main(){

    int N = 100000;
    int tot_won;

    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> distr(1,6);

    for ( size_t i = 0; i < N; i++) tot_won += throw_attack(distr, mt);

    std::cout << "Average won armies: "         << (double) tot_won / N         << std::endl;
    std::cout << "Average won armies per die: " << (double) tot_won / ( 3 * N ) << std::endl;

}