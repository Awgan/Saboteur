#include "card.hpp"

Card::Card()
{
	type		 	= notdef;
	id 				= -1;
	active 		= false;
	discarded = false;
	//std::cerr << "Card() : default constructor, ID : " << id << '\n';
}

Card::Card( cardType cType, int ID, bool act, bool dis )
	: type{cType}
	, id{ID}
	, active{act}
	, discarded{dis}
{
	//std::cerr << "Card() : constructor, ID : " << id << '\n';
}

Card::Card( const Card & card )
	: type{card.type}
	, id{card.id}
	, active{card.active}
	, discarded{card.discarded}
{
	std::cerr << "Card() : copy constructor, ID : " << id << '\n';
}

bool Card::operator==(const Card& c) const
{
	if(this == &c)
		return true;

	if(type == c.type && id == c.id)
		return true;

	return false;
}

//bool operator==(const Card& c, const Card& d)
//{
	//std::cerr << "Card operator==() entered\n";
	//if(&c == &d)
		//return true;

	//if(c.type == d.type && c.id == d.id)
		//return true;

	//return false;
//}

std::ostream & operator<<(std::ostream & cc, const Card & card)
{
	cc << "\tCard Address: " 		<< &card << "\n\t";
	cc << "Card Type: " 			<< card.type << "\n\t";
	cc << "Card ID: " 				<< card.id << "\n\t";
	cc << "Card Active: " 		<< card.active << "\n\t";
	cc << "Card Discarded: " 	<< card.discarded << "\n";
	return cc;
}

Card& Card::operator=(const Card& card)
{
	if(this == &card)
		return *this;

	type = card.type;
	id = card.id;
	active = card.active;
	discarded = card.discarded;

	return *this;
}



