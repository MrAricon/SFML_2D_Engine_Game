#include "../headers/Game.h"
#include "../headers/Player.h"

void Game::init()
{
	videoMode.height = 720;
	videoMode.width = 1080;
	window = new sf::RenderWindow(videoMode, "Berserk Race", sf::Style::Titlebar | sf::Style::Close);
	window->setPosition(sf::Vector2i(150, 0));
	window->setFramerateLimit(144);

	sound1Buff.loadFromFile("assets/diceSound1.wav");
	sound2Buff.loadFromFile("assets/diceSound2.wav");
	sound3Buff.loadFromFile("assets/diceSound3.wav");
	sound4Buff.loadFromFile("assets/button.wav");

	diceSound1.setBuffer(sound1Buff);
	diceSound2.setBuffer(sound2Buff);
	diceSound3.setBuffer(sound3Buff);
	buttonSound.setBuffer(sound4Buff);
}

void Game::pollEvents()
{
	while (window->pollEvent(ev))
	{
		sf::Vector2i winPos = window->getPosition();
		sf::Vector2i mouse = sf::Mouse::getPosition();
		switch (ev.type)
		{
		case sf::Event::Closed:
			window->close();
			break;
		case sf::Event::KeyPressed:
			switch (ev.key.code)
			{
			case sf::Keyboard::Escape:
				window->close();
				break;
			case sf::Keyboard::Space:
				if (diceBool == false)
				{
					buttonBool = true;
					buttonID = 1;
					buttonSound.play();
				}				
				break;
			case sf::Keyboard::N:
				if (diceBool == false)
				{
					buttonBool = true;
					buttonID = 2;
					buttonSound.play();
				}
				break;
			default:
				break;
			}
			break;
		case sf::Event::KeyReleased:
			switch (ev.key.code)
			{
			case sf::Keyboard::Escape:
				window->close();
				break;
			case sf::Keyboard::Space:
				if (diceBool == false)
				{
					diceBool = true;
					buttonBool = false;
					buttonSound.play();
				}				
				break;
			case sf::Keyboard::N:
				if (diceBool == false)
				{
					buttonBool = false;
					buttonSound.play();
				}
				if (nitro == false)
				{
					nitro = true;
				}
				else
				{
					nitro = false;
				}
				break;
			default:
				break;
			}
			break;
		case sf::Event::MouseButtonReleased:
			mousePosition.x = mouse.x - winPos.x - 8;
			mousePosition.y = mouse.y - winPos.y - 30;
			std::cout << mousePosition.x << " " << mousePosition.y << std::endl;
		}
	}
}

bool Game::getWindowOpen()
{
	return window->isOpen();
}

sf::Time Game::getDeltaTime()
{
	return deltaTime;
}

int Game::getDiceNum()
{
	return diceNum;
}

bool Game::getDiceBool()
{
	return diceBool;
}

int Game::getButtonID()
{
	return buttonID;
}

bool Game::getButtonBool()
{
	return buttonBool;
}

bool Game::getNitroBool()
{
	return nitro;
}

void Game::setDeltaTime(sf::Time pDeltaTime)
{
	deltaTime = pDeltaTime;
}

void Game::setDiceBool(bool pDiceBool)
{
	diceBool = pDiceBool;
}

void Game::setButtonBool(bool pButtonBool)
{
	buttonBool = pButtonBool;
}

void Game::trhowDice(float& time, int& frame, Player &pPlayer)
{
	if (time > 0.8)
	{
		frame = 5;
		if (time > 2) {
			time = 0;
			setDiceBool(false);
			if (pPlayer.getNitro() == true && pPlayer.getNitroCount() == 1)
			{
				pPlayer.setDistance(pPlayer.getDistance() + diceNum * 75);
			}
			else
			{
				pPlayer.setDistance(pPlayer.getDistance() + diceNum * 50);
			}
		}
	}
	else if (time > 0.4)
	{
		frame = 4;
	}
	else if (time > 0.3)
	{
		frame = 3;
	}
	else if (time > 0.2)
	{
		frame = 2;
	}
	else if (time > 0.1)
	{
		frame = 1;
	}
	else if (time > 0)
	{
		diceNum = std::rand() % 6 + 1;
		int sound = std::rand() % 3 + 1;
		frame = 0;
		if (sound == 1)
		{
			diceSound1.play();
		}
		else if (sound == 2)
		{
			diceSound2.play();
		}
		else if (sound == 3)
		{
			diceSound3.play();
		}
	}
}

void Game::render()
{
	window->clear();
}

void Game::update()
{
	pollEvents();
}