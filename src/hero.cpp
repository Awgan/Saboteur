
#include "hero.hpp"

void Hero::changeHeroType(heroType newType)
{
	typeHero = newType;
}

void Hero::changeName(std::string newName)
{
	name = newName;
}

bool Hero::operator==(const Hero& h) const
{
	if( this == &h )
		return true;

	if( typeHero == h.typeHero && name == h.name )
	{
		if( Card::operator==(h) )
			{
				return true;
			}
	}
	return false;
}

//bool operator==(const Hero& h, const Hero& g)
//{
	//std::cerr << "Hero operator==() entered\n";
	//if ( !( ((const Card &)h) == (const Card)g ) )
	//{
		//std::cerr << "Card operator==() : FALSE\n";
		//return false;
	//}
	//std::cerr << "Card operator==() : TRUE\n";
	//std::cerr << "Hero operator==() check\n";

	//if( h.typeHero == g.typeHero && h.name == g.name)
		//return true;

	//return false;
//}

std::ostream & operator<<(std::ostream & cc, const Hero & hh)
{
	cc << (const Card &)hh;
	cc << "Hero Type: " 	<< hh.typeHero << ' ';
	cc << "Name: " 				<< hh.name << ' ';
	return cc;
}
