#pragma once

#include <iostream>
#include <vector>
#include <random>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include "Player.h"

class Game
{
private:
	sf::VideoMode videoMode;
	sf::Event ev;
	sf::Vector2i mousePosition;
	sf::Time deltaTime;

	sf::SoundBuffer sound1Buff;
	sf::SoundBuffer sound2Buff;
	sf::SoundBuffer sound3Buff;
	sf::SoundBuffer sound4Buff;

	sf::Sound diceSound1;
	sf::Sound diceSound2;
	sf::Sound diceSound3;
	sf::Sound buttonSound;

	int diceNum;
	bool diceBool;

	int buttonID;
	bool buttonBool;

	bool nitro;

public:
	sf::RenderWindow* window = nullptr;

	void init();
	void pollEvents();
	void render();
	void update();

	// Getters

	bool getWindowOpen();
	sf::Time getDeltaTime();
	int getDiceNum();
	bool getDiceBool();
	int getButtonID();
	bool getButtonBool();
	bool getNitroBool();

	// Setters

	void setDeltaTime(sf::Time pDeltaTime);
	void setDiceBool(bool pDiceBool);
	void setButtonBool(bool pButtonBool);

	// Methods
	
	void trhowDice(float &time, int &frame, Player &pPlayer);
};