#include "menu.h"

Menu::Menu(sf::Font *font) {
 _font = font;
 this -> load();
}

Menu::Menu() {

}

/**
 * Display menu
 * @param _window
 */
void Menu::display(sf::RenderWindow &_window) {
    _boxes[0].setString("Start");
    _boxes[1].setString("Quitter");
    for(int i = 0 ; i < _boxes.size(); i++)
    {
        _boxes[i].setPosition(_window.getSize().y / 2, (_window.getSize().x / 2) + i *100);
        _window.draw(  _boxes[i]);
    }

}

/**
 * Load menu
 */
void Menu::load() {

    _boxes.emplace_back();
    _boxes.emplace_back();
    for(int i = 0 ; i < _boxes.size(); i++)
    {
        _boxes[i].setFont( *_font);
        sf::FloatRect box_start =  _boxes[i].getLocalBounds();
        _boxes[i].setOrigin((box_start.left + box_start.width) / 2,
                            (box_start.top + box_start.height) / 2);
    }
}

std::vector<sf::Text> Menu::getBoxes() {
    return _boxes;
}

Menu::~Menu() {

}


