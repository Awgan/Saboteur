
#include "card_pile.hpp"
#include "env.hpp"

#include <iostream>
#include <string.h>
#include <vector>


CardPile::CardPile( uint8_t cardsN )
{
	//std::cerr << "CardPile :: Default Constructor\n";

	if( cardsN > 3 && cardsN < 12 )
		cardsNumber = cardsN;
	else
	{
		//std::cerr << "CardPile() : number overshoot; number of cards is set to default\n";
		cardsNumber = 11;
	}

	cards.reserve( cardsNumber+1 );
}

CardPile::CardPile(std::initializer_list<Card> list)
: CardPile( static_cast<uint8_t>(list.size()) )
{
	//std::cerr << "CardPile :: Initializer List Constructor, list size: " << list.size() << '\n';

	for(Card l : list)
	{
		cards.push_back(l);
	}

	shuffle(1);
}

CardPile::CardPile( const CardPile& card )
{
	//std::cerr << "CardPile :: Copy Constructor\n";

	cardsNumber = card.cardsNumber;
	cards.reserve( cardsNumber);
	cards = card.cards;
}

CardPile::CardPile( CardPile&& card ) : CardPile{card}
{
	//std::cerr << "CardPile :: Move Constructor\n";

}

void CardPile::add(Card& card, bool shuf)
{
	//check if there is duplicate
	for(std::vector<Card>::iterator it = cards.begin(); it != cards.end(); ++it)
	{
		if( *it == card )			//exit, when ther is already identical card
			return;
	}

	cards.push_back(card);

	if(shuf == true)				//shuffle pile
		shuffle();
}

void CardPile::add(Card&& card, bool shuf)
{
	add(card,shuf);					//use add() with lreference parameter
}

void CardPile::remove(Card& card, bool shuf)
{
	for(std::vector<Card>::iterator it = cards.begin(); it != cards.end(); ++it)
	{
		//find the card
		if( *it == card )
		{
			std::cerr << "remove() : card found\n";
			cards.erase( it );
			break;
		}
	}

	if(shuf == true)				//shuffle pile
		shuffle();
}

Card CardPile::pickRandom()													//pick random Card
{
	uint8_t pileSize = size();

	if( pileSize < 1 )
		throw int{111};																	//ToDo :: change it, or rebuild, or repair

	std::srand( time(nullptr) );
	int rnd_x = rand();

	int rnd = (rnd_x)/( (RAND_MAX) / (pileSize) );		//calculate random card from available cards;

	Card cTmp = *( cards.begin() + rnd );							//last cards is before end() iterator; end() points to first after last element;

	cards.erase( cards.begin() + rnd ); 							//erase card number 'rnd'; copy lasts in 'cTmp'

	return cTmp;																			//return value not pointer
}


Card CardPile::pickTop()								//pick card from top of the pile and erase it from pile;
{																				//member function throw when pile size is less than 1
	uint8_t pileSize = size();

	if( pileSize < 1 )
		throw int{76};

	Card cTmp = *( cards.begin() );
	cards.erase( cards.begin() );

	return cTmp;
}

void CardPile::shuffle(uint8_t flips)
{
	while( flips > 0 )				//can't be 'flips >= 0'; it secures 'flips' from going under '0';
	{
		std::random_shuffle( cards.begin(), cards.end() );
		--flips;
	}
}

void CardPile::listAllCard()
{
	std::cout << "There is : " << (int)size() << " cards in pile\n";

	for( uint8_t i{0}, j{size()}; i < j; ++i)
	{
		std::cout << "Card no.: " << i+1 << '\n';
		std::cout << cards[i];
		std::cout << std::endl;
	}
}








//CardPile::CardPile(std::string fileName, uint8_t cardNum) :
	//cardsNumber{cardNum}
//{

	//maintainHeroCardFile( fileName );

	//std::ifstream inCardPile( fileName );					//Open File for read;

	//if(!inCardPile)																//Check if the file is opened
		//{
			//std::cout << "File doesn't existe\n";
			//throw 0;
		//}


	//std::vector<std::vector<std::string>> cardInfo(HERO_CARDS);
	//unsigned char n = 0;
	//std::string line;
	//std::getline(inCardPile, line);								//Get line until '\n'
	//char * ptch;																	//char pointer for getting tokens
	//while(inCardPile)															//End when EOF
	//{

		//if(line[0] == '#' || line[0] == ' ')				//Reject comments; comment is with sign '#'
		//{
			//std::getline(inCardPile, line);							//Get line until '\n'
			//continue;
		//}

		//ptch = strtok(&line[0],";");									//Get first token
		//unsigned char br = 0;													//Count tokens for each row

		//cardInfo[n].push_back((std::string)ptch);			//Add token to vector container
		//++br;
		//std::cout << ptch << ' ';
		//while ( (ptch = strtok(NULL, ";")) )						//Get next token until '\0' null character
		//{
			//std::cout << ptch << ' ';
			//cardInfo[n].push_back((std::string)ptch); 	//Add token to vector container
			//++br;
			//if( br > 3 )
			//{
				//++n;
				//std::cout << '\n';
				//br = 0;
			//}
		//}
		//std::getline(inCardPile, line);								//Get line until '\n'
	//}


	//for(std::vector<std::vector<std::string>>::iterator it = cardInfo.begin(); it != cardInfo.end(); ++it)
	//{
		//for( std::vector<std::string>::iterator itb = (*it).begin(); itb != (*it).end(); ++itb)
		//{
			//std::cout << *itb << ' ';
		//}
		 //std::cout << '\n';
	//}

	////cards.resize(11);
	////for(std::vector<int8_t> & vlt : cardInfo)
	////{
		////cards.push_back(Hero(vlt[0], vlt[1], false, false, vlt[2], vlt[3]));
	////}



	//inCardPile.close();

//};
