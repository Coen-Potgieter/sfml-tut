#include <SFML/Window.hpp>
#include <iostream>

int main() {
    sf::Window window(sf::VideoMode({ 800, 600}), "My Window");

    window.setPosition({ 10, 50 });
    window.setSize({ 640, 480 });
    window.setTitle("New Window Title");

    sf::Vector2u size = window.getSize();
    auto [ width, height ] = size;

    std::cout << width << std::endl;
    std::cout << height << std::endl;

    std::cout << window.hasFocus() << std::endl;





    // run program as long as window is open
    while (window.isOpen()) {


        // poll if any events are queued
        while (const std::optional event = window.pollEvent()) {


            // if one of the events is "close requested", then close the window
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }
    }
}

