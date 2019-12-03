
#include <iostream>
#include "timer.h"

Timer::Timer() {
}

Timer::Timer(sf::Font* font) {
  _font = font;
  this -> loadTimer();
}

void Timer::display(sf::RenderWindow &_window, sf::Time &time) {


    int minutes =  floor(time.asSeconds()/60);
    int seconds = floor(time.asSeconds()-(minutes*60));
    _time_text.setString( std::to_string(minutes) + " : " + std::to_string(seconds) );
    _window.draw(_time_text);
}

void Timer::loadTimer() {
    _time_text.setFont(*_font);
    _time_text.setPosition(100, 0);
    sf::FloatRect box = _time_text.getLocalBounds();
    _time_text.setOrigin(box.left + box.width ,
                         box.top + box.height);

}

Timer::~Timer() {

}
