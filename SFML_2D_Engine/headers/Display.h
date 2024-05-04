#pragma once

#include "Game.h"
#include "Player.h"

class Display
{
public:
	static void quad(sf::Vector2f position, sf::Vector2f size, sf::Vector2f texSize, int suit, int number, sf::RenderWindow* window, sf::Texture texture);
	static void drawPlayer(Player pPlayer, sf::Vector2f size, sf::Vector2f textureSize, sf::RenderWindow* window);
};