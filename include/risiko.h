#ifndef RISIKO_H
#define RISIKO_H

#include <vector>
#include <algorithm>
#include <random>

namespace risiko {

int throw_attack( std::uniform_int_distribution<int> &distr, std::mt19937 &mt, int attackerArmies, int defenderArmies){

    std::vector<int> attack;
    std::vector<int> defense;

    for( size_t i = 0; i < attackerArmies; i++) attack.push_back( distr(mt) );
    for( size_t i = 0; i < defenderArmies; i++) defense.push_back( distr(mt) );

    std::sort( attack.begin(),  attack.end(),  std::greater<int>() );
    std::sort( defense.begin(), defense.end(), std::greater<int>() );

    int won = 0;

    int size = std::min(attack.size(), defense.size());

    for ( size_t i = 0 ; i < size; i++){
        if (attack[i] > defense[i]) won++;
    }

    return won;
}

int attack_kamchatka( int attackerArmies, int defenderArmies ){

    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> distr(1,6);

    while( ( attackerArmies > 0 )  && ( defenderArmies > 0 ) ){
		
		int actualAttackerArmies = std::min (3, attackerArmies);
        int actualDefenderArmies = std::min (3, defenderArmies);
		int won = throw_attack( distr, mt, actualAttackerArmies, actualDefenderArmies );
		defenderArmies -= won;
		attackerArmies -= actualDefenderArmies - won;

	}

    return ( attackerArmies > 0 ) ? attackerArmies : 0;

}


}

#endif