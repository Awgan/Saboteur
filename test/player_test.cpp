
#include "../src/hero.hpp"
#include "../src/player.hpp"

#include <iostream>
#include <string>

void wynik(const bool wyn);

bool playerTest(Player* player, Card* heroCard, int gold, int deckSize, int specialSize);

int main(int argc, char* argv[])
{

	Player p01{};
	wynik( playerTest(&p01,nullptr,0,0,0) );

	Hero h01{heroType::saboteur, "Einstain"};

	//Player p02{ Hero{heroType::saboteur, (const char*)"Einstain"} };



	return 0;
}


void wynik(const bool wyn)
{
	std::cout << "Test P01 : "; if (wyn) std::cout<<"PASS\n"; else std::cout<<"FAIL\n";
}

bool playerTest(Player* player, Card* heroCard, int gold, int deckSize, int specialSize)
{
	if(		 player->heroCard() == heroCard
			&& player->gold() == gold
			&& player->sizeDeck() == deckSize
			&& player->sizeSpecial() == specialSize
		)
		return true;

	return false;
}
