#pragma once
#include "invaders.h"
#include "player.h"
#include "bullet.h"
#include "collisionSystem.h"
#include "enemiesManager.h"
#include "bulletsManager.h"
#include "menu.h"
#include "timer.h"
#include "levelConfig.h"

/*
** Game handling
*/
class Game
{
private:
    sf::RenderWindow _window;

    //Level Infos
    int _currentLevel;
    int _maxLevel = 3;
    LevelConfig _levelConfig;

    //Timer
    Timer _timer;
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    void updateTimer();

    //Text config
    sf::Font _font;
    sf::Text _full_text;

    //Game Entities
    Player _player;
    EnemiesManager enemiesManager;
    BulletsManager bulletsManager;
    Menu _menu;

    //Main Game function
    void load();
    void initGame();
    void quitGame();

    //Game state
    enum GameState { onMenu, onGame, GameOver, Win};
    GameState _gameState = onMenu;

	//Main functions in game loop
    void update();
    void draw();
    void spawn();

    //Loading functions
    void setupAreas();
    void loadTextures();

    //LevelFunction
    void initLevel(int levelNb);
    void endLevel();
    void endLevel(GameState state);
    void handleEndLevel();

    //drawing functions
    void drawFullScreenText(std::string text);

    //Events function
	void HandleEvent(sf::Event event, bool isActive);

public:
    Game(void);
    ~Game();
    void loop();

    static CollisionSystem collisionSystem;
    static Limits windowsSize;
    static Limits enemiesArea;
    static Limits uiArea;



};
