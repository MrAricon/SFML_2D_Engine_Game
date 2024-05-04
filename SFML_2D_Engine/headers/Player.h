#pragma once

#include <iostream>
#include <vector>
#include <random>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Player
{
private:
	float distance;
	bool nitro;
	int nitroCount;
	bool selected;
	bool moving;
	bool turn;
	bool win;

	sf::Vector2f position;
	sf::Texture texture;

	sf::Vector2f floorPosition;
	sf::Texture floorTex;

	sf::Vector2f skyPosition;
	sf::Texture skyTex;

public:
	Player(bool pSelected, sf::Texture pTexture, sf::Texture pFloorTexture, sf::Texture pSkyTexture);

	// Getters

	float getDistance();
	bool getNitro();
	int getNitroCount();
	bool getSelected();
	bool getMoving();
	sf::Vector2f getPosition();
	sf::Texture getTexture();
	sf::Texture getSkyTexture();
	sf::Texture getFloorTexture();
	sf::Vector2f getSkyPosition();
	sf::Vector2f getFloorPosition();
	bool getTurn();
	bool getWin();

	// Setters

	void setDistance(float pDistance);
	void setNitro(bool pNitro);
	void setNitroCount(int pNitroCount);
	void setSelected(bool pSelected);
	void setMoving(bool pMoving);
	void setPosition(sf::Vector2f pPositon);
	void setTexture(sf::Texture pTexture);
	void setTurn(bool pTurn);
	void setWin(bool pWin);
	
	// Methods
	void movement(sf::Time deltaTime, Player &pOponent);
	void checkWin();

};