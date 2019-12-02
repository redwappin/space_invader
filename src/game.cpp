#include "game.h"
#include <player.h>
#include <iostream>

Limits Game::windowsSize = Limits();
Limits Game::enemiesArea = Limits();
CollisionSystem Game::collisionSystem = CollisionSystem();

Game::Game()
{
    windowsSize.max_height = 900;
    windowsSize.max_width = 1200;
    _window.create(sf::VideoMode(windowsSize.max_width, windowsSize.max_height), "Simple invaders", sf::Style::Close | sf::Style::Titlebar);
    _window.setVerticalSyncEnabled(true);
    _window.setKeyRepeatEnabled(false);

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

    enemiesArea.max_height = 800;
    enemiesArea.min_height = 300;
    enemiesArea.max_width = 1100;
    enemiesArea.min_height = 0;

    //Setup movable
    enemiesManager = EnemiesManager();
    enemiesManager.enemyTexture = &_textures[3];
    enemiesManager.spawn();
    enemiesManager.draw(_window);
	_player = Player(&_textures[0]);
	_player.setSpeed(5);
}

void Game::loadTextures()
{
	for (int i = 0; i < 3; i++)
	{
		_textures.emplace_back(sf::Texture());
	}
	_textures[0].loadFromFile("assets/luigi.png");
	_textures[1].loadFromFile("assets/carapace.png");
    _textures[3].loadFromFile("assets/ghost.png");
}

void::Game::updatePlayer()
{
    _player.move(v_playerMove.x,v_playerMove.y);
    _player.draw(_window);
}

void::Game::updateBullets()
{
	for (int i = 0; i < _bullets.size(); ++i)
	{
		_bullets[i].draw(_window);
		_bullets[i].move(0,-1);

		if (_bullets[i].getPosition().y > windowsSize.max_width || _bullets[i].getPosition().y < 0)
		{
			_bullets.erase(_bullets.begin() + i);
		}
	};
}

void Game::updateEnemies() {

}

void Game::update()
{
    enemiesManager.draw(_window);
	this->updatePlayer();
	this->updateBullets();

}

void Game::HandleEvent(sf::Event event, bool isActive)
{
    int keyCode = event.key.code;
    int x_move = 0;
    if(isActive){
        x_move = (keyCode == 71)? -1 : (keyCode == 72)? 1 : 0;
    }else{
        x_move = (keyCode == 71)? 1 : (keyCode == 72)? -1 :0;
        if(keyCode == 57){
            _bullets.emplace_back(&_textures[1]);
			_player.shoot(_bullets.back());
        }
    }

    int y_move = 0.0f;
    sf::Vector2i v_newMove (x_move,y_move);
    v_playerMove += v_newMove;

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




