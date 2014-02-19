#include "Game.h"

Game::Game() : mWindow(sf::VideoMode(640, 480), "SFML Application Chapter 1"), mPlayer(), mIsMovingUp(false), mIsMovingDown(false), mIsMovingLeft(false), mIsMovingRight(false)
{
	mPlayer.setRadius(40.f);
	mPlayer.setPosition(100.f, 100.f);
	mPlayer.setFillColor(sf::Color::Red);
	playerSpeed = 500;
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
			handlePlayerInput(event.key.code, true);
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

	if (mIsMovingUp)
		movement.y -= playerSpeed;
	if (mIsMovingDown)
		movement.y += playerSpeed;
	if (mIsMovingLeft)
		movement.x -= playerSpeed;
	if (mIsMovingRight)
		movement.x += playerSpeed;

	mPlayer.move(movement * deltaTime.asSeconds());
}

void Game::render()
{
	mWindow.clear();
	mWindow.draw(mPlayer);
	mWindow.display();
}