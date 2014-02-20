#include "Game.hpp"

Game::Game() : mWindow(sf::VideoMode(640, 480), "SFML Application"), mCurrentPlayer(), mIsMovingUp(false), mIsMovingDown(false), mIsMovingLeft(false), mIsMovingRight(false)
{
	mPlayers.push_back(Player("Jeb Kerman",sf::Vector2f(500.f,500.f))); // Add a default player
	mPlayers.push_back(Player("Bill Kerman")); // Add another player
	m_playerSelected = mPlayers.begin();
	m_playerSelected->setRadius(40.f);
	m_playerSelected->setPosition(100.f, 100.f);
	m_playerSelected->setFillColor(sf::Color::Red);

	m_playerSelected++;
	m_playerSelected->setRadius(20.f);
	m_playerSelected->setPosition(200.f,200.f);
	m_playerSelected->setFillColor(sf::Color::Blue);

	m_playerSelected = mPlayers.begin();

	timePerFrame = sf::seconds(1.f / 60.f);
}

void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate;
	while (mWindow.isOpen())
	{
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents();
			update(timePerFrame);
		}
		render();
	}
}

void Game::showPlayers() {
	std::cout << "Player list:" << std::endl ;
	for (std::vector<Player>::iterator it = mPlayers.begin(); it != mPlayers.end(); ++it) {
		std::cout << it->toString() << std::endl;
	}
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{
	if (key == sf::Keyboard::W)
		mIsMovingUp = isPressed;
	if (key == sf::Keyboard::A)
		mIsMovingLeft = isPressed;
	if (key == sf::Keyboard::S)
		mIsMovingDown = isPressed;
	if (key == sf::Keyboard::D)
		mIsMovingRight = isPressed;
	
}

void Game::processEvents()
{
	sf::Event event;
	while (mWindow.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			mWindow.close();

		switch (event.type)
		{
		case sf::Event::KeyPressed:
		  if (event.key.code == sf::Keyboard::Tab)
			{
				if (++m_playerSelected == mPlayers.end())
					m_playerSelected = mPlayers.begin();

				std::cout << "Selected Player: " << m_playerSelected->toString() << std::endl;
			} 
			else 
			{
				handlePlayerInput(event.key.code, true);
			}
			break;
		case sf::Event::KeyReleased:
			handlePlayerInput(event.key.code, false);
			break;
		}

	}
}

void Game::update(sf::Time deltaTime)
{
	sf::Vector2f movement(0.f, 0.f);
	sf::Vector2f playerSpeed = m_playerSelected->getSpeed();

	if (mIsMovingUp)
		movement.y -= playerSpeed.y;
	if (mIsMovingDown)
		movement.y += playerSpeed.y;
	if (mIsMovingLeft)
		movement.x -= playerSpeed.x;
	if (mIsMovingRight)
		movement.x += playerSpeed.x;

	m_playerSelected->move(movement * deltaTime.asSeconds());
}

void Game::render()
{
	mWindow.clear();
	for (std::vector<Player>::iterator it = mPlayers.begin(); it != mPlayers.end(); ++it) {
		mWindow.draw(*it);
	}
	mWindow.display();
}