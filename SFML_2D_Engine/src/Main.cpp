#include "../headers/Game.h"
#include "../headers/Player.h"
#include "../headers/Display.h"

int main() 
{
	Game game;
	game.init();

	sf::Texture backgroundTex;
	backgroundTex.loadFromFile("assets/background.png");
	sf::Texture gutsTex1;
	gutsTex1.loadFromFile("assets/guts1.png");
	sf::Texture gutsTex2;
	gutsTex2.loadFromFile("assets/guts2.png");
	sf::Texture griffithTex1;
	griffithTex1.loadFromFile("assets/griffith1.png");
	sf::Texture griffithTex2;
	griffithTex2.loadFromFile("assets/griffith2.png");
	sf::Texture floorTex;
	floorTex.loadFromFile("assets/floor.png");
	sf::Texture gutsSkyTex;
	gutsSkyTex.loadFromFile("assets/guts_sky.png");
	sf::Texture griffithSkyTex;
	griffithSkyTex.loadFromFile("assets/griffith_sky.png");
	sf::Texture diceTex;
	diceTex.loadFromFile("assets/dice_textures.png");
	sf::Texture spaceButtonTex;
	spaceButtonTex.loadFromFile("assets/space_button.png");
	sf::Texture nButton;
	nButton.loadFromFile("assets/n_button.png");
	sf::Texture gutsWinTex;
	gutsWinTex.loadFromFile("assets/guts_win.png");
	sf::Texture griffithWinTex;
	griffithWinTex.loadFromFile("assets/griffith_win.png");

	sf::RectangleShape spaceRec;

	spaceRec.setTexture(&spaceButtonTex);
	spaceRec.setSize(sf::Vector2f(116.0f, 76.0f));
	spaceRec.setPosition(sf::Vector2f(514.0f, 528.0f));

	sf::RectangleShape nRec;

	nRec.setTexture(&nButton);
	nRec.setSize(sf::Vector2f(68.0f, 76.0f));
	nRec.setPosition(sf::Vector2f(246.0f, 528.0f));

	sf::RectangleShape gutsWinRec;

	// 540 360

	gutsWinRec.setTexture(&gutsWinTex);
	gutsWinRec.setSize(sf::Vector2f(1080.0f, 720.0f));

	sf::RectangleShape griffithWinRec;

	griffithWinRec.setTexture(&griffithWinTex);
	griffithWinRec.setSize(sf::Vector2f(1080.0f, 720.0f));

	sf::RectangleShape backgroundRec;

	backgroundRec.setTexture(&backgroundTex);
	backgroundRec.setSize(sf::Vector2f(1080.0f, 720.0f));

	Player guts(true, gutsTex1, floorTex, gutsSkyTex);
	Player griffith(false, griffithTex1, floorTex, griffithSkyTex);

	sf::Clock deltaClok;

	float deltaTime;

	float animation = 0;
	float animation1 = 0;
	float animation2 = 0;

	int frame = 0;
	int frame2 = 0;

	int count = 0;

	while (game.getWindowOpen() && guts.getWin() == false && griffith.getWin() == false)
	{
		std::srand(time(NULL));

		game.update();

		guts.setNitro(game.getNitroBool());

		deltaTime = game.getDeltaTime().asSeconds();

		animation1 += deltaTime;

		if (animation1 > 0.5) {
			guts.setTexture(gutsTex2);
			griffith.setTexture(griffithTex2);
			if (animation1 > 1) animation1 = 0;
		} else {
			guts.setTexture(gutsTex1);
			griffith.setTexture(griffithTex1);
		}
		
		Display::quad(sf::Vector2f(730.0f, 490.0f), sf::Vector2f(208.0f, 154.0f), sf::Vector2f(66.0f, 49.0f), game.getDiceNum() - 1, 5, game.window, diceTex);

		if (game.getDiceBool() == true && guts.getMoving() == false && guts.getTurn() == true) {
			animation += deltaTime;
			game.trhowDice(animation, frame, guts);
			std::cout << frame << std::endl;
			Display::quad(sf::Vector2f(730.0f, 490.0f), sf::Vector2f(208.0f, 154.0f), sf::Vector2f(66.0f, 49.0f), game.getDiceNum() - 1, frame, game.window, diceTex);
		}
		else if (griffith.getTurn() == false) {
			Display::quad(sf::Vector2f(730.0f, 490.0f), sf::Vector2f(208.0f, 154.0f), sf::Vector2f(66.0f, 49.0f), game.getDiceNum() - 1, 5, game.window, diceTex);
		}

		if (griffith.getTurn() == true && griffith.getMoving() == false && griffith.getTurn() == true) {
			animation2 += deltaTime;
			game.trhowDice(animation2, frame2, griffith);
			Display::quad(sf::Vector2f(730.0f, 490.0f), sf::Vector2f(208.0f, 154.0f), sf::Vector2f(66.0f, 49.0f), game.getDiceNum() - 1, frame2, game.window, diceTex);
		}
		else if (guts.getTurn() == false) {
			Display::quad(sf::Vector2f(730.0f, 490.0f), sf::Vector2f(208.0f, 154.0f), sf::Vector2f(66.0f, 49.0f), game.getDiceNum() - 1, 5, game.window, diceTex);
		}
		
 		if (guts.getTurn() == true)
		{
			guts.movement(game.getDeltaTime(), griffith);
		}
		else if (griffith.getTurn() == true) 
		{
			griffith.movement(game.getDeltaTime(), guts);
		}
		
		Display::drawPlayer(guts, sf::Vector2f(102.0f, 130.0f), sf::Vector2f(51.0f, 65.0f), game.window);

		Display::drawPlayer(griffith, sf::Vector2f(108.0f, 130.0f), sf::Vector2f(54.0f, 65.0f), game.window);

		game.window->draw(backgroundRec);

		if (game.getButtonBool() && game.getDiceBool() == false) {
			switch (game.getButtonID())	{
			case 1:
				game.window->draw(spaceRec);
				break;
			case 2:
				game.window->draw(nRec);
				break;
			default:
				break;
			}
		}

		guts.checkWin();
		griffith.checkWin();

		game.window->display();

		game.render();

		game.setDeltaTime(deltaClok.restart());
	}

	while (game.window->isOpen() == true)
	{
		game.update();

		Display::quad(sf::Vector2f(730.0f, 490.0f), sf::Vector2f(208.0f, 154.0f), sf::Vector2f(66.0f, 49.0f), game.getDiceNum() - 1, 5, game.window, diceTex);

		deltaTime = game.getDeltaTime().asSeconds();

		Display::drawPlayer(guts, sf::Vector2f(102.0f, 130.0f), sf::Vector2f(51.0f, 65.0f), game.window);

		Display::drawPlayer(griffith, sf::Vector2f(108.0f, 130.0f), sf::Vector2f(54.0f, 65.0f), game.window);

		game.window->draw(backgroundRec);

		if (guts.getWin() == true)
		{
			gutsWinRec.setPosition(sf::Vector2f(gutsWinRec.getPosition().x, gutsWinRec.getPosition().x));
			game.window->draw(gutsWinRec);
		}
		else
		{
			griffithWinRec.setPosition(sf::Vector2f(griffithWinRec.getPosition().x, 0.0f));
			game.window->draw(griffithWinRec);
		}

		game.window->display();

		game.render();

		game.setDeltaTime(deltaClok.restart());
	}

	return 0;
}