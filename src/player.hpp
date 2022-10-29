
#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#define MAX_CARD_NUMBER		11		//max card in hand; max card 11, max player is 11;

#include "card.hpp"
#include "hero.hpp"

#include <vector>


class Player
{
	private:
		Hero*								m_hero;					//hero card
		std::vector<Card> 	m_cardDeck;			//deck of cards;
		std::vector<Card>		m_specialCard;	//deck of special card which stop the hero; player get stop card from another players;
		int 								m_gold;					//amount of gold;

	public:

		Player();
		Player(const Hero&);

		~Player(){ delete m_hero; };

		void add(const Hero&);						//add Hero card;
		void change(const Hero&);					//cast Hero card and take another;
		void swapHero(Player&);						//swap Hero card with another Player

		void initCardDeck();
		void add(const Card&);						//add one Card to deck
		void remove(const Card&);					//remove one Card from deck
		void swapDeck(Player&);						//swap card deck with Player;
		int sizeDeck();										//size of card deck
		void showDeck();									//show card in deck;

		bool isSpecial(const Card&);			//check if there is already the special card in deck
		int sizeSpecial();								//size of special card deck
		void showSpecial();
		std::vector<Card>& getSpecial();	//get access to special deck to add special card

		void playCard(const int n);				//play card number n from deck;
		void choosePlace();								//choose place to play card;

		const int gold() const { return m_gold; }	//get number of golds;
		void addGold( const int gol );		//add new gold;
		void removeGold( const int gol );		//remove from gold;

		//Player class must be frind class for class Board


};

#endif
