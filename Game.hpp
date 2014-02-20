#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Player.hpp"

class Game
{
public:
	Game();
	void run();
	void showPlayers();

private:
	void processEvents();
	void update(sf::Time);
	void render();
	void handlePlayerInput(sf::Keyboard::Key, bool);

	sf::Time timePerFrame;
	sf::RenderWindow mWindow;
	std::vector<Player> mPlayers;
	std::vector<Player>::iterator m_playerSelected ;
	
	bool mIsMovingUp, mIsMovingDown, mIsMovingLeft, mIsMovingRight;
};