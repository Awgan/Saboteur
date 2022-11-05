#ifndef CARD_HPP
#define CARD_HPP

#include <iostream>

enum cardType { notdef=-1, hero = 0, special = 1, hall = 2 };

class Card
{
	private:

		cardType 	type;
		int 			id;
		bool 			active;
		bool 			discarded;

	public:

		Card();

		Card(cardType cType, int ID, bool act = false, bool dis = false);

		Card(const Card & card);

		virtual ~Card(){std::cerr << "Card() : destructor, ID : " << id << " address: " << this << '\n';}

		const int 			getId() const {return id;}
		const cardType 	getCardType() const {return type;}
		Card * 					get() {return this;}
		bool 						isActive() const {return active;}
		bool 						isDiscard() const {return discarded;}
		bool 						activate() {return active = discarded?false:true;}
		bool 						discard() {active = false; return discarded = true;}

		bool						operator==(const Card& c) const;
		//friend bool			operator==(const Card& c, const Card& d);

		friend std::ostream & operator<<(std::ostream & cc, const Card & card);

		Card& operator=(const Card& card);

};

#endif
