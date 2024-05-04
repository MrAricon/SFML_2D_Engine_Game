#include "../headers/Player.h"

Player::Player(bool pSelected, sf::Texture pTexture, sf::Texture pFloorTexture, sf::Texture pSkyTexture)
{
	selected = pSelected;
	texture = pTexture;
	if (selected == true)
	{
		setPosition(sf::Vector2f(150.0f, 158.0f));
		skyPosition = sf::Vector2f(148.0f, 156.0f);
		floorPosition = sf::Vector2f(148.0f, 288.0f);
		turn = true;
	}
	else {
		setPosition(sf::Vector2f(150.0f, 318.0f));
		skyPosition = sf::Vector2f(148.0f, 316.0f);
		floorPosition = sf::Vector2f(148.0f, 448.0f);
	}
	skyTex = pSkyTexture;
	floorTex = pFloorTexture;
	nitro = true;
	nitroCount = 1;
	moving = false;
	distance = 150.0f;
	win = false;
}

float Player::getDistance()
{
	return distance;
}

bool Player::getNitro()
{
	return nitro;
}

int Player::getNitroCount()
{
	return nitroCount;
}

bool Player::getSelected()
{
	return selected;
}

bool Player::getMoving()
{
	return moving;
}

sf::Vector2f Player::getPosition()
{
	return position;
}

sf::Texture Player::getTexture()
{
	return texture;
}

sf::Texture Player::getSkyTexture()
{
	return skyTex;
}

sf::Texture Player::getFloorTexture()
{
	return floorTex;
}

sf::Vector2f Player::getSkyPosition()
{
	return skyPosition;
}

sf::Vector2f Player::getFloorPosition()
{
	return floorPosition;
}

bool Player::getTurn()
{
	return turn;
}

bool Player::getWin()
{
	return win;
}

void Player::setDistance(float pDistance)
{
	distance = pDistance;
}

void Player::setNitro(bool pNitro)
{
	nitro = pNitro;
}

void Player::setNitroCount(int pNitroCount)
{
	nitroCount = pNitroCount;
}

void Player::setSelected(bool pSelected)
{
	selected = pSelected;
}

void Player::setMoving(bool pMoving)
{
	moving = pMoving;
}

void Player::setPosition(sf::Vector2f pPositon)
{
	position = pPositon;
}

void Player::setTexture(sf::Texture pTexture)
{
	texture = pTexture;
}

void Player::setTurn(bool pTurn)
{
	turn = pTurn;
}

void Player::setWin(bool pWin)
{
	win = pWin;
}

void Player::movement(sf::Time deltaTime, Player &pOponent)
{
	if (getPosition().x != getDistance()) {
		setMoving(true);
		if (true)
		{

		}
		if (getPosition().x < getDistance()) {
			if (getNitro() == true && nitroCount == 1) {
				setPosition(sf::Vector2f(getPosition().x + 150 * deltaTime.asSeconds(), getPosition().y));
				floorPosition = sf::Vector2f(floorPosition.x - 75 * deltaTime.asSeconds(), floorPosition.y);
				skyPosition = sf::Vector2f(skyPosition.x - 18.75 * deltaTime.asSeconds(), skyPosition.y);
			}
			else {
				setPosition(sf::Vector2f(getPosition().x + 100 * deltaTime.asSeconds(), getPosition().y));
				floorPosition = sf::Vector2f(floorPosition.x - 50 * deltaTime.asSeconds(), floorPosition.y);
				skyPosition = sf::Vector2f(skyPosition.x - 12.5 * deltaTime.asSeconds(), skyPosition.y);
			}
			if (getPosition().x > getDistance()) {
				setPosition(sf::Vector2f(getDistance(), getPosition().y));
				setTurn(false);
				pOponent.setTurn(true);
				if (nitro == true) {
					nitro = false;
					nitroCount = 0;
				}
			}
		}
		else if (getPosition().x > getDistance()) {
			if (getNitro() == true && nitroCount == 1) {
				setPosition(sf::Vector2f(getPosition().x - 150 * deltaTime.asSeconds(), getPosition().y));
				floorPosition = sf::Vector2f(floorPosition.x + 75 * deltaTime.asSeconds(), floorPosition.y);
				skyPosition = sf::Vector2f(skyPosition.x + 18.75 * deltaTime.asSeconds(), skyPosition.y);
			}
			else {
				setPosition(sf::Vector2f(getPosition().x - 100 * deltaTime.asSeconds(), getPosition().y));
				floorPosition = sf::Vector2f(floorPosition.x + 50 * deltaTime.asSeconds(), floorPosition.y);
				skyPosition = sf::Vector2f(skyPosition.x + 12.5 * deltaTime.asSeconds(), skyPosition.y);
			}
			if (getPosition().x < getDistance()) {
				setPosition(sf::Vector2f(getDistance(), getPosition().y));
				setTurn(false);
				pOponent.setTurn(true);
				if (nitro == true) {
					nitro = false;
					nitroCount = 0;
				}
			}
		}
	}
	else {
		setMoving(false);
	}
}

void Player::checkWin()
{
	if (getPosition().x > 830.0f)
	{
		position.x = 830.0f;
		win = true;
	}
}
