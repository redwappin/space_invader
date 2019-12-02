#pragma once
#include "invaders.h"
#include "player.h"
#include "bullet.h"
#include "collisionSystem.h"
#include "enemiesManager.h"

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

    std::vector<sf::Texture> _textures;
    Player _player;
    std::vector<Bullet> _bullets;

    sf::Vector2i v_playerMove;

    void load();
    void wideText(const std::string &text, const sf::Color &color);
	void loadTextures();

    void update();
    void updatePlayer();
    void updateBullets();
    void updateEnemies();

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
