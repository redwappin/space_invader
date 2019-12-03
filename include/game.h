#pragma once
#include "invaders.h"
#include "player.h"
#include "bullet.h"
#include "collisionSystem.h"
#include "enemiesManager.h"
#include "life.h"
#include "timer.h"
#include "menu.h"
#include "levelConfig.h"

/*
** Game handling
*/
class Game
{
private:
    sf::RenderWindow _window;
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;

    sf::Font _font;
    sf::Text _full_text;
    Menu _menu;

    std::vector<sf::Texture> _textures;
    Player _player;
    Timer _timer;
    LevelConfig _levelConfig;
    std::vector<Bullet> _bullets;
    std::vector<Life> _player_lives;

    sf::Vector2i v_playerMove;

    int level = 1;

    enum GameState { onMenu, onGame, GameOver, Win};

    GameState _gameState = onMenu;
    void load();
	void loadTextures();

	void initGame();
    void update();
    void updatePlayer();
    void updateBullets();
    void wideText();
    void drawText(std::string text);
    void updateEnemies();
    void updateTimer();

	void HandleEvent(sf::Event event, bool isActive);

public:
    Game(void);
    ~Game();
    void loop();

    EnemiesManager enemiesManager;
    static CollisionSystem collisionSystem;
    static Limits windowsSize;
    static Limits enemiesArea;
};
