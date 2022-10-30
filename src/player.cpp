
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
