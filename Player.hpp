#ifndef PLAYER_HPP
#define PLAYER_HPP

// Headers
#include <sstream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

class Player : public sf::CircleShape
{
public:
	Player();
	Player(sf::String name) : m_playername(name),  m_playerspeed(sf::Vector2f(200.0f,200.0f)) {}
	Player(sf::String name,sf::Vector2f speed) : m_playername(name), m_playerspeed(speed) {}

	std::string		toString();
	sf::Vector2f	getSpeed();

private:	
	std::string		m_playername;		// Player name
	sf::Vector2f	m_playerspeed;		// Player speed settings
	
};

#endif PLAYER_HPP