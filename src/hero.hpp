#ifndef HERO_HPP
#define HERO_HPP

#include "card.hpp"

#include <iostream>
#include <vector>



enum heroType { miner = 0, saboteur = 1 };


class Hero : public Card
{
	private:

		heroType 				typeHero;		//hero type; chose from two
		std::string 		name;				//name

	public:

		Hero( heroType type = miner, std::string hName = "miner" )
			: Card()
			, typeHero{type}
			, name{hName}
		{ }

		Hero(  cardType cType, uint8_t ID, bool act = false, bool dis = false, heroType type = miner, std::string hName = "none")
			: Card{cType, ID, act, dis}
			, typeHero{type}
			, name{hName}
		{ }

		Hero(const Card &)
		{ }

		virtual ~Hero()
		{ };

		const heroType & 		getHeroType() const { return typeHero; };
		void 								changeHeroType(heroType newType);
		void 								changeName(std::string NewName);

		bool								operator==(const Hero& h) const;
		//friend bool					operator==(const Hero& h, const Hero& g);

		friend std::ostream & operator<<(std::ostream & cc, const Hero & hh);

};

#endif
