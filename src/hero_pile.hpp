#ifndef HERO_PILE_HPP
#define HERO_PILE_HPP

#include "card_pile.hpp"


class HeroPile : public CardPile
{
	private:

		struct sCardNum				//card number structure; there are separates variable for each card type
		{
			uint8_t miner{};
			uint8_t saboteur{};
		}s_cardsNumber;

	public:

		HeroPile()
		: CardPile() {};

		HeroPile( uint8_t playerNum = 10 )
		: CardPile{ playerNum + 1 } {}

		~HeroPile() {}

		void 		prepareHeroCards();

		uint8_t size() const { return s_cardsNumber.miner+s_cardsNumber.saboteur; }
};

#endif

