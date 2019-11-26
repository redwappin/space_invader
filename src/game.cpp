#include "game.h"
#include <player.h>
#include <iostream>

Game::Game()
{
    _window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Simple invaders", sf::Style::Close | sf::Style::Titlebar);
    _window.setVerticalSyncEnabled(true);
    load();
}

Game::~Game()
{
}

void Game::load()
{
	this ->loadTextures();
    _font.loadFromFile("assets/Sansation.ttf");
    _full_text.setFont(_font);
    _full_text.setCharacterSize(50);

	_player = Player(&_textures[0]);
	_player.setSpeed(5);
}

void Game::loadTextures()
{
	for (int i = 0; i < 2; i++)
	{
		_textures.push_back(sf::Texture());
	}
	_textures[0].loadFromFile("assets/luigi.png");
	_textures[1].loadFromFile("assets/carapace.png");

}

void Game::wideText(const std::string &text, const sf::Color &color)
{
    _full_text.setString(text);
    sf::FloatRect box = _full_text.getLocalBounds();
    _full_text.setOrigin(box.left + box.width / 2.0f,
                         box.top + box.height / 2.0f);
    _full_text.setPosition(WINDOW_WIDTH / 2.0f, WINDOW_HEIGHT / 2.0f);
    _full_text.setFillColor(color);
    _window.draw(_full_text);
}

void::Game::updatePlayer() 
{
	if (isLeftArrowPress)
	{
		_player.move(-1);
	}
	if (isRightArrowPress) 
	{
		_player.move(1);
	}
	_player.draw(_window);
}

void::Game::updateBullets()
{
	for (int i = 0; i < _bullets.size(); ++i)
	{
		_bullets[i].draw(_window);
		_bullets[i].move(-8);

		if (_bullets[i].getSprite().getPosition().y > WINDOW_WIDTH || _bullets[i].getSprite().getPosition().y < 0)
		{
			_bullets.erase(_bullets.begin() + i);
		}
	};
}

void Game::update()
{
	//wideText(timeSinceLastUpdate.asSeconds, sf::Color::Cyan);
	this->updatePlayer();
	this->updateBullets();
	

}

void Game::HandleEvent(sf::Event event, bool isActive)
{
	if (isActive) {
		if (event.key.code == 71)
		{
			isLeftArrowPress = true;
		}
		if (event.key.code == 57)
		{
			if (!isSpaceBarPressed)
			{
				_bullets.push_back(Bullet(&_textures[1]));
				_player.shoot(_bullets.back());
				isSpaceBarPressed = true;
			}		
		}
		if (event.key.code == 72) {
			isRightArrowPress = true;
		}
	}
	else {
		if (event.key.code == 57)
		{
			isSpaceBarPressed = false;
		}

		if (event.key.code == 71)
		{
			isLeftArrowPress = false;
		}

		if (event.key.code == 72)
		{
			isRightArrowPress = false;
		}
	}

}

void Game::loop()
{
    while (this->_window.isOpen())
    {
		timeSinceLastUpdate += clock.restart();
        this->_window.clear(sf::Color::Black);
        sf::Event event;
        while (this->_window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::KeyPressed:
				this->HandleEvent(event, true);
                break;

			case sf::Event::KeyReleased:
				this->HandleEvent(event, false);
			break;
            case sf::Event::Closed:
                this->_window.close();
                break;
            default:
                break;
            }
        }
        this->update();
        this->_window.display();
    }
}