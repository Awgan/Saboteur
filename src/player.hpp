
#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#define MAX_CARD_NUMBER		11		//max card in hand; max card 11, max player is 11;

#include "card.hpp"
#include "hero.hpp"
#include "card_pile.hpp"

#include <vector>


class Player
{
	private:
		Hero*								m_hero;					//hero card
		std::vector<Card> 	m_cardDeck;			//deck of cards;
		std::vector<Card>		m_specialDeck;	//deck of special card which stop the hero; player get stop card from another players;
		int 								m_gold;					//amount of gold;

		CardPile*						m_cardPile;			//pointer to a CardPile

	public:

		Player();
		Player(const Hero& hero);
		Player(const Hero& hero, CardPile* pile);

		~Player(){ delete m_hero; };

		const bool isHero(){return m_hero;};//check if there is hero;
		void addHero(const Hero&);				//add Hero card;
		void changeHero(const Hero&);			//cast Hero card and take another;
		void swapHero(Player&);						//swap Hero card with another Player

		void initCardDeck();							//ToDo
		void addDeckCard(const Card&);		//add one Card to deck
		void removeDeckCard(const int n);	//remove one Card from deck; begin() + n
		void swapDeck(Player&);						//swap card deck with Player;
		int  sizeDeck();									//size of card deck
		void showDeck();									//show card in deck;

		bool isSpecial(const Card&);			//check if there is already the special card in deck
		int  sizeSpecial();								//size of special card deck
		void addSpecial(const Card&);
		void showSpecial();
		void removeSpecial(const int n);	//remove special card only if there is special card for repair;

		const int gold() const { return m_gold; }				//get number of golds;
		void addGold( const unsigned int gold );				//add new gold; usigned int protect from negative numbers
		void removeGold( const unsigned int gold );			//remove from gold; usigned int protect from negative numbers

		const Card playCard(const int n);//play card number n from deck;

		//Player class must be frind class for class Board

		//functions for testing

		const Hero* heroCard(){return m_hero;}

		bool operator==(const Player& player) const;

};

#endif
