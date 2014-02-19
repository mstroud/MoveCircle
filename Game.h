#include <SFML/Graphics.hpp>

class Game
{
public:
	Game();
	void run();

private:
	void processEvents();
	void update(sf::Time);
	void render();
	void handlePlayerInput(sf::Keyboard::Key, bool);

	float playerSpeed;
	sf::Time timePerFrame;
	sf::RenderWindow mWindow;
	sf::CircleShape mPlayer;
	bool mIsMovingUp, mIsMovingDown, mIsMovingLeft, mIsMovingRight;
};