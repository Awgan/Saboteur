
#include "../src/hero.hpp"
#include "../src/player.hpp"

#include <iostream>
#include <string>

void wynik(const bool wyn);

bool playerTest(Player* player, const Card* heroCard, int gold, int deckSize, int specialSize);

bool playerTest_m_hero(Player* player, const Hero* hero);
bool playerTest_m_cardDeck(Player* player, const int size);
bool playerTest_m_specialDeck(Player* player, const int size);
bool playerTest_m_gold(Player* player, const int gold);

int main(int argc, char* argv[])
{
//1
	Player p01{};
	wynik( playerTest(&p01,nullptr,0,0,0) );
//2
	Hero h01{heroType::saboteur, "Einstain"};
	Player p02{ h01 };
	const Card* cardTemp = p02.heroCard();
	wynik( playerTest(&p02, cardTemp, 0, 0, 0) );
//3
	p01.add(h01);
	wynik( playerTest_m_hero(&p01, &h01) );

//4
	Hero h02{heroType::miner, "Galileusz"};
	cardTemp = p01.heroCard();
	p01.change( h02 );
	wynik( playerTest_m_hero(&p01, &h02) );






	return 0;
}


void wynik(const bool wyn)
{
	static int testLevel = 1;
	std::cout << "Test P" << testLevel << " : "; if (wyn) std::cout<<"PASS\n"; else std::cout<<"FAIL\n";
	++testLevel;
}

bool playerTest(Player* player, const Card* heroCard, int gold, int deckSize, int specialSize)
{
	if(		 player->heroCard() == heroCard
			&& player->gold() == gold
			&& player->sizeDeck() == deckSize
			&& player->sizeSpecial() == specialSize
		)
		return true;

	return false;
}

bool playerTest_m_hero(Player* player, const Hero* hero)
{
	return *(player->heroCard()) == *hero;
}

bool playerTest_m_cardDeck(Player* player, const int size)
{
	return player->sizeDeck()== size;
}

bool playerTest_m_specialDeck(Player* player, const int size)
{
	return player->sizeSpecial() == size;
}

bool playerTest_m_gold(Player* player, const int gold)
{
	return player->gold() == gold;
}
