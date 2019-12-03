#include "game.h"
#include <player.h>
#include <iostream>

Limits Game::windowsSize = {0,1200,0,900};
Limits Game::enemiesArea ;
Limits Game::uiArea;
CollisionSystem Game::collisionSystem = CollisionSystem();

/**
 * Constructor
 * Init Window Size
 * Create Window
 */
Game::Game()
{
    _window.create(sf::VideoMode(windowsSize.max_width, windowsSize.max_height), "Simple invaders", sf::Style::Close | sf::Style::Titlebar);
    _window.setVerticalSyncEnabled(true);
    _window.setKeyRepeatEnabled(false);

    load();
}

/**
 * Setup height and width areas
 * y axis : Top screen(0) to bottom(windowsHeight)
 */
void Game::setupAreas(){
    //take 70% of screen
    float enemiesHeight = 0.7f*windowsSize.max_height/1;
    //take 10% of screen
    float uiHeight = 0.1f*windowsSize.max_height/1;

    //Enemies Area
    enemiesArea = {0,windowsSize.max_width,0.0f ,enemiesHeight + uiHeight};

    //Ui Area
    uiArea = {0,windowsSize.max_width,0,uiHeight};
}

/**
 * Load Game (Textures, Areas, Menus)
 */
void Game::load()
{
    setupAreas();

    //Loads textures
	this ->loadTextures();

	//text entity to draw text on screen
    _full_text.setFont(_font);
    _full_text.setCharacterSize(100);

    initGame();
}

/**
 * Load Textures
 */
void Game::loadTextures()
{
    //Load player Texture
    Player::texture.loadFromFile("assets/luigi.png");
    Life::texture.loadFromFile("assets/pixel-heart.png");

    //Load Enemy Texture
    Enemy::texture.loadFromFile("assets/ghost.png");

    //Load bullets Textures
    BulletsManager::textures["Player"].loadFromFile("assets/carapace.png");
    BulletsManager::textures["Enemy"].loadFromFile("assets/carapace.png");

    _font.loadFromFile("assets/Mario-Kart-DS.ttf");
}

/**
 * Init Game
 * Instantiate player
 * We keep it accross the game;
 */
void Game::initGame()
{
    //instantiate Menu
    _menu = Menu(&_font);

    //init player Enity
    _player = Player();
    _player.setSpeed(5);
    _player.setLives(3);

    //init timer
    _timer = Timer(&_font);
}

/**
 * Init Level
 * Instantiate Movables Manager (Bullets & Enemies)
 * Instantiate Enemies
 * Draw Player & Enemies
 */
void Game::initLevel(int levelNb)
{
    drawFullScreenText("Niveau " + std::to_string(levelNb));
    _currentLevel = levelNb;

    //Display level number
    this -> _window.display();
    std::this_thread::sleep_for (std::chrono::seconds(1));
    this -> _window.clear();

    //set state onGame
    _gameState = onGame;

    //get levels conf
    auto levelConf = _levelConfig.findByLevelNumber(levelNb);

    //start timer
    timeSinceLastUpdate = sf::Time::Zero;
    clock.restart();

    //Setup movable Manager
    enemiesManager = EnemiesManager(levelConf.enemiesconf);
    bulletsManager = BulletsManager();


    //Pass ref needed
    enemiesManager.setBulletsManager(&bulletsManager);
    _player.setBulletsManager(&bulletsManager);

    //Draw movables
    _player.setPosition(windowsSize.max_width / 2.0f, windowsSize.max_height - _player.getBounds().height);
    enemiesManager.Draw(_window);
    _player.draw(_window);
}

/**
 * Update Movables (Bullets, Enemies, Player)
 */
void Game::update()
{
    //Check player life
    if(_player.isDead){
        endLevel(GameOver);
        return;
    }

    //Check enemy number
    if(enemiesManager.getEnemiesNb()==0){
        endLevel(Win);
        return;
    }


    bulletsManager.Update();
    enemiesManager.Update();
    _player.update();
}

/**
 * Spawn Movables (Bullets, Enemies)
 */
void Game::spawn(){
    //Spawn player bullets
    if(_player.canShoot){
        _player.Shoot();
    }

    //Spawn Enemies Bullets
    enemiesManager.Shoot();

    //Spawn new Enemies
}

/**
 * Draw All Entities in function of Game State
 */
void Game::draw() {
    switch (_gameState){
        case onGame:
            _player.Draw(_window);
            enemiesManager.Draw(_window);
            bulletsManager.Draw(_window);
            break;
        case onMenu:
            _menu.display(_window);
            break;
        case GameOver:
            drawFullScreenText("Game Over");
            break;
        case Win:
            drawFullScreenText("Win");
            break;
    }
}

/**
 * Handle event on keyboard key
 * @param event
 * @param isActive : if key pressed or realease
 */
void Game::HandleEvent(sf::Event event, bool isActive)
{
    //get mouse event in click on menu
    if(event.type == sf::Event::MouseButtonPressed){
        sf::Vector2f Mouse = _window.mapPixelToCoords(sf::Mouse::getPosition(_window));
        if (_menu.getBoxes()[0].getGlobalBounds().contains(Mouse)) {
            _gameState = onGame;
            this->initLevel(1);
        }else if (_menu.getBoxes()[1].getGlobalBounds().contains(Mouse)) {
            this->quitGame();
        }
    }

    //Construct new dir vector Player
    //Handle shoot
    int keyCode = event.key.code;
    int x_move = 0;
    if(isActive){
        x_move = (keyCode == 71)? -1 : (keyCode == 72)? 1 : 0;
    }else{
        x_move = (keyCode == 71)? 1 : (keyCode == 72)? -1 :0;
        if(keyCode == 57){
            _player.canShoot =  true;
        }
    }

    int y_move = 0.0f;
    sf::Vector2i v_newMove (x_move,y_move);
    _player.playerMove += v_newMove;

}

/**
 * Game loop
 * Switch functions in function of Game State
 * Handle event in function of game state
 */
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
				if(_gameState==onGame)this->HandleEvent(event, true);
                break;

			case sf::Event::KeyReleased:
                if(_gameState==onGame)this->HandleEvent(event, false);
			break;
			case sf::Event::MouseButtonPressed:
                if(_gameState==onMenu)this->HandleEvent(event, false);
			    break;
            case sf::Event::Closed:
                    this->quitGame();
                break;
            default:
                break;
            }
        }

        //if ongame update and spawn entities
        if(_gameState == onGame){
            this->update();
            this->spawn();
            this->updateTimer();
        }
        this->draw();
        this->_window.display();

        // if state win or game over wait 5 secondes before resend to menu
        if(_gameState== GameOver || _gameState == Win){
            this->handleEndLevel();
        }
    }
}

/**
 * Display timer
 */
void::Game::updateTimer() {
    timeSinceLastUpdate += clock.restart();
    _timer.display(_window, timeSinceLastUpdate);
}

/**
 * Display a text in full screen
 * @param text to display
 */
void Game::drawFullScreenText(std::string text) {
    _full_text.setString(text);
    _window.draw(_full_text);
}

/**
 * Handle end level
 * After screen draw win or lose
 */
void Game::handleEndLevel() {
    std::this_thread::sleep_for(std::chrono::seconds(3));
    if(_gameState == Win && _currentLevel != _maxLevel) initLevel(_currentLevel+1);
    else{
        _gameState = onMenu;
        _player.setLives(3);
    }
}

/**
 * End the current level
 * @param gameState
 */
void Game::endLevel(GameState gameState) {
    endLevel();
    _gameState = gameState;
}

/**
 * Delete all entity except player
 * player is delete only if gameOver
 * Player is the only instance of Movable entity that not created by dynamic allocation
 */
void Game::endLevel() {
    bulletsManager.deleteEntity();
    enemiesManager.deleteEntity();
}

/**
 * Quit Game
 * Destroy all pointer allocated by new
 * Avoid Memory leak
 */
void Game::quitGame() {
    if(_gameState == onGame){
        this->endLevel();
    }
    this->_window.close();
}


/**
 * Game Destructor
 */
Game::~Game()
{
}










