#pragma once
#include "invaders.h"
#include "player.h"
#include "bullet.h"

/*
** Game handling
*/
class Game
{
private:
    void update();
	void updatePlayer();
	void updateBullets();
    void load();
    void wideText(const std::string &text, const sf::Color &color);
	void loadTextures();

	sf::Clock clock;

	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	bool isSpaceBarPressed = false;
	bool isLeftArrowPress = false;
	bool isRightArrowPress = false;

	std::vector<sf::Texture> _textures;

	sf::Texture _playerTexture;
	sf::Texture _bulletTexture;

	Player _player;

	std::vector<Bullet> _bullets;

	void HandleEvent(sf::Event event, bool isActive);

    sf::RenderWindow _window;
    sf::Font _font;
    sf::Text _full_text;

public:
    Game(void);
    ~Game();
    void loop();
    static constexpr int WINDOW_WIDTH = 1200;
    static constexpr int WINDOW_HEIGHT = 900;
};
