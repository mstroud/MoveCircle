#include "Player.hpp"

sf::Vector2f Player::getSpeed() {
	return m_playerspeed ;
}

std::string Player::toString() {
	std::stringstream ss ;
	ss << " name: " << m_playername ;
	ss << " pos: [" << getPosition().x << ", " << getPosition().y << "]" ;
	ss << " speed: [" << getSpeed().x << ", " << getSpeed().y << "]";
	return ss.str();
}