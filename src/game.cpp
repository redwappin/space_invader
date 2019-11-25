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
    _font.loadFromFile("assets/Sansation.ttf");
    _full_text.setFont(_font);
    _full_text.setCharacterSize(50);
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

void Game::update()
{
	///wideText("MARYLOUUUUUUUUUU...", sf::Color::Cyan);
	_player.draw(_window);
}

void Game::loop()
{
    while (this->_window.isOpen())
    {
        this->_window.clear(sf::Color::Black);
        sf::Event event;
        while (this->_window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::KeyPressed:
				if (event.key.code == 71)
				{
					_player.move(-8);
				}
				if (event.key.code == 72) {
					_player.move(8);
				}
                break;
            case sf::Event::KeyReleased:
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