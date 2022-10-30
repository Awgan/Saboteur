
#include "player.hpp"

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
	if( m_hero != nullptr || player.getHero() != nullptr )	//swap if at least one player has Hero card
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
		case event:
			//ToDo:: check if there is already this type of event card
			m_specialCard.push_back(card);
		break;
		case hall:
			if(m_cardDeck.size
			m_cardDeck.push_back(card);
		break;
		default:
		break;
	}

}

void Player::remove(const Card& card)
{
	//TODO
}
