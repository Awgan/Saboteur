
#include "player.hpp"

#include <algorithm>
#include <cmath>

Player::Player()
: m_hero{nullptr}
, m_gold{0}
{}

Player::Player(const Hero& hero)
: m_gold{0}
{
	if( m_hero == nullptr )
	{
		m_hero = new Hero;
	}

	*m_hero = hero;
}

void Player::add(const Hero& hero)
{
	if( m_hero == nullptr )
	{
		m_hero = new Hero;
		*m_hero = hero;
	}
	else
	{
		std::cerr << "Ther is already the Hero\n";
	}
}
void Player::change(const Hero& hero)
{
	if( m_hero != nullptr )
	{
		*m_hero = hero;
	}
	else
	{
		add(hero);
	}
}

void Player::swapHero(Player& player)
{
	if( m_hero != nullptr || player.m_hero != nullptr )	//swap if at least one player has Hero card
	{
		Hero* tmp{m_hero};
		m_hero = player.m_hero;
		player.m_hero = tmp;
	}
	else
	{
		//do not swap when both have not Hero card
	}
}

void Player::add(const Card& card)
{
	cardType c_type = card.getCardType();

	switch(c_type)
	{
		case hero:
			change(card);
		break;

		case special:
			addSpecial(card);
		break;

		case hall:
			if(sizeDeck() < 6)
			{
				m_cardDeck.push_back(card);
			}
		break;

		default:
		break;
	}

}

void Player::remove(const int n)
{
	const int size = sizeDeck();
	if (size < 6)																	//Max card deck is 5
	{
		m_cardDeck.erase(m_cardDeck.begin() + n);
	}
	else
	{
		std::cerr << "Wrong card!\n";
	}
}

void Player::swapDeck( Player& player )
{
	std::vector<Card> temp{m_cardDeck};
	m_cardDeck = player.m_cardDeck;
	player.m_cardDeck = temp;
}

int Player::sizeDeck()
{
	return m_cardDeck.size();
}

void Player::showDeck()
{
	using v_it=std::vector<Card>::iterator;

	v_it b_it = m_cardDeck.begin();
	v_it e_it = m_cardDeck.end();

	std::for_each(b_it, e_it, [](Card& c){ std::cerr << c; });
}

bool Player::isSpecial(const Card& card)
{
	return card.getCardType() == cardType::special;
}

int Player::sizeSpecial()
{
	return m_specialDeck.size();
}

void Player::addSpecial(const Card& card)
{

	for( auto f_card : m_specialDeck )										//Check if there is the same card
	{
		if( f_card.getCardType() == card.getCardType() )		//If yes -> return, don't add
		{
			return;
		}
	}

	m_specialDeck.push_back(card);													//If no -> add card

}

void Player::showSpecial()
{
	using v_it=std::vector<Card>::iterator;

	v_it b_it = m_specialDeck.begin();
	v_it e_it = m_specialDeck.end();

	std::for_each(b_it, e_it, [](Card& c){ std::cerr << c; });
}

void Player::removeSpecial(const int n)
{
	const int size = sizeSpecial();
	if (size < 4)																	//Max special deck is 3 cards
	{
		m_specialDeck.erase(m_specialDeck.begin() + n);
	}
	else
	{
		std::cerr << "Wrong special card!\n";
	}
}

void Player::addGold( const unsigned int gold )
{
	m_gold = m_gold + gold;
}

void Player::removeGold( const unsigned int gold )
{
	if( std::abs(int(gold)) > m_gold )			//You can't have negative number of golds;
	{
		m_gold = 0;
	}
	else
	{
		m_gold = m_gold - gold;
	}
}

const Card& Player::playCard(const int n)
{
	//ToDo
	//'n' must be lower than 6
	//if no -> return and give signal that operation wrong
	//if yes -> remove card from deck, and return it

	/*Card temp{m_cardDeck[n-1]};
	remove(n);*/
}

