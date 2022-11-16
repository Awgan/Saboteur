
#include "../src/hero.hpp"
#include "../src/player.hpp"

#include <iostream>
#include <string>

void wynik(const bool wyn);

bool playerTest(Player* player, const Card* heroCard, int gold, int deckSize, int specialSize);
bool playerTest(const Player* pl_1, const Player* pl_2);
bool playerTest_m_hero(Player* player, const Hero* hero);
bool playerTest_m_cardDeck(Player* player, const int size);
bool playerTest_m_specialDeck(Player* player, const int size);
bool playerTest_m_gold(Player* player, const int gold);
bool playerTest_isHero();
bool playerTest_addDeckCard();
bool playerTest_removeDeckCard();

int main(int argc, char* argv[])
{
//1 constructor()
	Player p01{};
	wynik( playerTest(&p01,nullptr,0,0,0) );

//2 constructor()
	Hero h01{heroType::saboteur, "Einstain"};
	Player p02{ h01 };
	const Hero* cardTemp_1 = p02.heroCard();
	wynik( playerTest(&p02, cardTemp_1, 0, 0, 0) );

//3 addHero()
	p01.addHero(h01);
	wynik( playerTest_m_hero(&p01, &h01) );

//4 changeHero()
	Hero h02{heroType::miner, "Galileusz"};
	//cardTemp_1 = p01.heroCard();
	p01.changeHero( h02 );
	wynik( playerTest_m_hero(&p01, &h02) );

//5&6 swapHero()
	cardTemp_1 = p01.heroCard();										//save heroes cards; use them for checking
	const Hero* cardTemp_2 = p02.heroCard();
	p01.swapHero(p02);															//swap heroes cards
	wynik( playerTest_m_hero( &p01, cardTemp_2 ) );
	wynik( playerTest_m_hero( &p02, cardTemp_1 ) );

//7 isHero()
	wynik(playerTest_isHero());

//8 addDeckcard()
	wynik(playerTest_addDeckCard());

//9 removeDeckCard()




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
	if(		 *((Card*)player->heroCard()) == *heroCard
			&& player->gold() == gold
			&& player->sizeDeck() == deckSize
			&& player->sizeSpecial() == specialSize
		)
		return true;

	return false;
}

bool playerTest(const Player* pl_1, const Player* pl_2)
{
	if( *pl_1 == *pl_2 )
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

bool playerTest_isHero()
{
	Player p03;
	if( p03.isHero() != false )
		return false;

	p03.addHero(Hero{heroType::saboteur, "Felix Cat"});
	if( p03.isHero() != true )
		return false;

	return true;
}

bool playerTest_addDeckCard()
{
	//Init Player;
	Player p04(Hero{cardType::hero, 123, false, false, heroType::miner, "Nemo"});

	//Add first card and check if there is one card;
	p04.addDeckCard(Card{cardType::hall, 12, false, false});
	if( p04.sizeDeck() != 1 )
	{
		std::cerr << "Test addDeckCard() :: wrong #1. size: " << p04.sizeDeck() <<'\n';
		return false;
	}
	//Add another 4 cards to have max possible 5 cards; GOOD when there are 5 cards;
	p04.addDeckCard(Card{cardType::hall, 13, false, false});
	p04.addDeckCard(Card{cardType::hall, 14, false, false});
	p04.addDeckCard(Card{cardType::hall, 15, false, false});
	p04.addDeckCard(Card{cardType::hall, 16, false, false});
	if( p04.sizeDeck() != 5 )
	{
		std::cerr << "Test addDeckCard() :: wrong #2. size: " << p04.sizeDeck() <<'\n';
		return false;
	}
	//Add another card to full deck; GOOD when there is only 5 cards, not 6;
	p04.addDeckCard(Card{cardType::hall, 17, false, false});
	if( p04.sizeDeck() != 5 )
	{
		std::cerr << "Test addDeckCard() :: wrong #3. size: " << p04.sizeDeck() <<'\n';
		return false;
	}

	return true;
}

bool playerTest_removeDeckCard()
{

	return true;
}


