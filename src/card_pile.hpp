
#ifndef CARD_PILE_HPP
#define CARD_PILE_HPP

#define CARD_FILE "/home/rafal/Programowanie/C++/Saboteur/src/pileHeroes.txt"

#include <algorithm>
#include <cstring>
#include <fstream>
#include <initializer_list>
#include <stdlib.h>
#include <string>
#include <vector>

#include "card.hpp"
#include "hero.hpp"


class CardPile
{
	private:

		uint8_t				 			cardsNumber{};			//number of Cards

		std::vector<Card>		cards{};						//collect of Cards objects

	public:

		virtual void 	add(Card& card, bool shuf = true);					//add a card
		virtual void  add(Card&& card, bool shuf = true);
						void 	remove(Card& card, bool shuf = false); 			//remove a card;

	public:

		CardPile( uint8_t cardsN = 11 );										//default cards number 11 for max 10 players

		CardPile( std::initializer_list<Card> list );

		CardPile( const CardPile& card );

		CardPile( CardPile&& card );

		virtual ~CardPile() {/*std::cerr << "CardPile() : DESTRUCTOR\n";*/};

						uint8_t	getCardsNumber() 	const 	{ return cardsNumber; }
		virtual uint8_t size() 						const 	{ return cards.size(); }

		virtual Card 		pickRandom();
		virtual Card 		pickTop();

						void 		shuffle( uint8_t flips = 1 );

						void 		listAllCard();

};


#endif
