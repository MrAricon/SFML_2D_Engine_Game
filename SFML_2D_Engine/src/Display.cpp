#include "../headers/Game.h"
#include "../headers/Display.h"

void Display::quad(sf::Vector2f position, sf::Vector2f size, sf::Vector2f texSize, int suit, int number, sf::RenderWindow* window, sf::Texture texture)
{
	sf::VertexArray triangleStrip(sf::Quads, 4);

	triangleStrip[0].position = position;
	triangleStrip[1].position = sf::Vector2f(position.x + size.x, position.y);
	triangleStrip[2].position = sf::Vector2f(position.x + size.x, position.y + size.y);
	triangleStrip[3].position = sf::Vector2f(position.x, position.y + size.y);

	triangleStrip[0].texCoords = sf::Vector2f((0 + number) * texSize.x, (0 + suit) * texSize.y);
	triangleStrip[1].texCoords = sf::Vector2f(texSize.x * number + texSize.x, (0 + suit) * texSize.y);
	triangleStrip[2].texCoords = sf::Vector2f(texSize.x * number + texSize.x, texSize.y * suit + texSize.y);
	triangleStrip[3].texCoords = sf::Vector2f((0 + number) * texSize.x, texSize.y * suit + texSize.y);

	window->draw(triangleStrip, &texture);
}

void Display::drawPlayer(Player pPlayer, sf::Vector2f size, sf::Vector2f textureSize, sf::RenderWindow *window)
{
	quad(pPlayer.getSkyPosition(), sf::Vector2f(888.0f, 132.0f), sf::Vector2f(444.0f, 66.0f), 0, 0, window, pPlayer.getSkyTexture());
	quad(pPlayer.getFloorPosition(), sf::Vector2f(1186, 28.0f), sf::Vector2f(593.0f, 14.0f), 0, 0, window, pPlayer.getFloorTexture());
	quad(pPlayer.getPosition(), size, textureSize, 0, 0, window, pPlayer.getTexture());
}