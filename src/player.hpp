
#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#define MAX_CARD_NUMBER		11		//max card in hand; max card 11, max player is 11;

#include "card.hpp"
#include "hero.hpp"

#include <vector>


class Player
{
	private:
		Hero								m_hero;					//hero card
		std::vector<Card> 	m_cardDeck;			//deck of cards;
		std::vector<Card>		m_specialCard;	//deck of special card which stop the hero
		int 								gold;						//amount of gold;

	public:
		Player(const Hero&);

		~Player(){};

		void add(const Hero&);						//add Hero card;
		void change(const Hero&);					//cast Hero card and take another;
		void swapHero(Player&);						//swap Hero card with another Player

		void initCardDeck();
		void add(const Card&);						//add one Card to deck
		void remove(const Card&);					//remove one Card from deck
		void swapDeck(Player&);						//swap card deck with Player;
		int sizeDeck();										//size of card deck
		void showdeck();									//show card in deck;

		bool isSpecial(const Card&);			//check if there is already the special card in deck
		int sizeSpecial();								//size of special card deck
		std::vector<Card>& getSpecial();	//get access to special deck to add special card

		void playCard(const int n);				//play card number n from deck;
		void choosePlace();								//choose place to play card;

		//Player class must be frind class for class Board


};

#endif
