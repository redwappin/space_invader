#include "game.h"
#include <player.h>
#include <iostream>
#include <stdio.h>

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
	this -> wideText();
    _font.loadFromFile("assets/Mario-Kart-DS.ttf");
    _gameState = onMenu;
    _menu = Menu(&_font);
    _player = Player(&_textures[0]);
    _timer = Timer(&_font);

    enemiesArea.max_height = 800;
    enemiesArea.min_height = 300;
    enemiesArea.max_width = 1100;
    enemiesArea.min_height = 0;

    //Setup movable
    enemiesManager = EnemiesManager();
    enemiesManager.enemyTexture = &_textures[2];
    enemiesManager.spawn();
}

void Game::wideText() {

    _full_text.setFont(_font);
    sf::FloatRect box = _full_text.getGlobalBounds();
    _full_text.setOrigin((box.left + box.width) / 2,(box.top + box.height) / 2);
    _full_text.setPosition(_window.getSize().y/2.0f, _window.getSize().y/2.0f);
    _full_text.setScale(2, 2);
}


void Game::initGame()
{
    _player.setSpeed(5);
    _player.setLife(3);
    _player.setPosition(_window.getView().getSize().x / 2.0f, _window.getView().getSize().y - _player.getBounds().height);
    for (int i = 0; i < _player.getLives(); ++i)
    {
        _player_lives.emplace_back(&_textures[3]);
        _player_lives.back().setPosition(  (_window.getSize().x -(_window.getSize().x/ 4))+i * 100, 0);
    };

    auto levelConf = _levelConfig.findByLevelNumber(level);
    timeSinceLastUpdate = sf::Time::Zero;

    drawText("Niveau " + std::to_string(level));
    this -> _window.display();
    std::this_thread::sleep_for (std::chrono::seconds(2));
    this -> _window.clear();
//    //Setup movable
//    enemiesManager = EnemiesManager();
//    enemiesManager.enemyTexture = &_textures[2];
//    enemiesManager.spawn();






}

void Game::loadTextures()
{
	for (int i = 0; i < 4; i++)
	{
		_textures.emplace_back(sf::Texture());
	}
	_textures[0].loadFromFile("assets/luigi.png");
	_textures[1].loadFromFile("assets/carapace.png");
    _textures[2].loadFromFile("assets/ghost.png");
    _textures[3].loadFromFile("assets/pixel-heart.png");
}

void::Game::updateTimer() {
    timeSinceLastUpdate += clock.restart();

    _timer.display(_window, timeSinceLastUpdate);
}
void::Game::updatePlayer()
{
    if(floor(timeSinceLastUpdate.asSeconds()) == 15)
    {
        _player.looseLife();
    }
    _player.move(v_playerMove.x,v_playerMove.y);
    if(_player.getLives() == 0)
    {
        _gameState = Win;
    }
    for (int i = 0; i < _player.getLives(); ++i)
        {
            _player_lives[i].draw(_window);
            if(_player_lives.size() > _player.getLives())
            {
                _player_lives.erase(_player_lives.begin()+i);
            }
            if(_player.getLives() == 0)
            {
                _gameState = GameOver;
            }
        };
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
    if(_gameState == onGame)
    {
        enemiesManager.draw(_window);
        this->updatePlayer();
        this->updateBullets();
        this->updateTimer();
    } else if ( _gameState == onMenu){
        _menu.display(_window);
    } else if (_gameState == GameOver){
        this -> drawText("Game Over");
        this -> clearGame();
        this -> _window.display();
        std::this_thread::sleep_for (std::chrono::seconds(4));
        this -> _window.clear(sf::Color::Black);
        _gameState = onMenu;
    }
    else if (_gameState == Win){
        this -> drawText("You Win");
        this -> _window.display();
        this -> clearGame();
        std::this_thread::sleep_for (std::chrono::seconds(4));
        this -> _window.clear(sf::Color::Black);
        level = level + 1;
        this -> initGame();
        _gameState = onGame;
    }


}

void Game::HandleEvent(sf::Event& event, bool isActive)
{
    int keyCode = event.key.code;
    if(_gameState == onGame)
    {
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
    }else if (_gameState == onMenu) {
        if(event.type == sf::Event::MouseButtonPressed){
            sf::Vector2f Mouse = _window.mapPixelToCoords(sf::Mouse::getPosition(_window));
            if (_menu.getBoxes()[0].getGlobalBounds().contains(Mouse)) {
                level = 1;
                _gameState = onGame;
                this->initGame();
            }else if (_menu.getBoxes()[1].getGlobalBounds().contains(Mouse)) {
                this->_window.close();
            }
        }
    }

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
				this->HandleEvent(event, true);
                break;

			case sf::Event::KeyReleased:
				this->HandleEvent(event, false);
			    break;
			case sf::Event::MouseButtonPressed:
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

void Game::drawText(std::string text) {
_full_text.setString(text);
_window.draw(_full_text);
}

void Game::clearGame() {
    _bullets.clear();
    _player_lives.clear();
    //delete &enemiesManager;
}





