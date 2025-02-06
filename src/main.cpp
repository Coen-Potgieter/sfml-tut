#include <SFML/Graphics.hpp>
#include <stdint.h>
#include <iostream>
#include <unordered_map>

#include "./include/player.h"
#include "./include/constants.h"

void updateMovement(std::unordered_map<sf::Keyboard::Scancode, uint8_t>& states, 
                    const sf::Keyboard::Scancode& keyPressed, 
                    const bool pressed);

int main() {

    sf::ContextSettings settings;
    settings.antiAliasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}), "My Window", sf::Style::Default, sf::State::Windowed, settings);
    window.setVerticalSyncEnabled(true);
    window.setKeyRepeatEnabled(false);

    Player me;

    std::unordered_map<sf::Keyboard::Scancode, uint8_t> movementStates = {
        {sf::Keyboard::Scancode::D, 0},
        {sf::Keyboard::Scancode::A, 0},
        {sf::Keyboard::Scancode::Right, 0},
        {sf::Keyboard::Scancode::Left, 0},
    };


    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            } else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
                updateMovement(movementStates, keyPressed->scancode, true);
            } else if (const auto* keyReleased = event->getIf<sf::Event::KeyReleased>()) {
                updateMovement(movementStates, keyReleased->scancode, false);
            }
        }

        if (movementStates[sf::Keyboard::Scancode::D] || movementStates[sf::Keyboard::Scancode::A]) {
            if (movementStates[sf::Keyboard::Scancode::D] > movementStates[sf::Keyboard::Scancode::A]) {
                me.moveRight();
            } else {
                me.moveLeft();
            } 
        }

        if (movementStates[sf::Keyboard::Scancode::Right] || movementStates[sf::Keyboard::Scancode::Left]) {
            if (movementStates[sf::Keyboard::Scancode::Right] > movementStates[sf::Keyboard::Scancode::Left]) {
                me.rotateRight();
            } else {
                me.rotateLeft();
            } 
        }
        window.clear(sf::Color::Black);
        me.draw(window);
        window.display();
    }
}


void updateMovement(std::unordered_map<sf::Keyboard::Scancode, uint8_t>& states, 
                    const sf::Keyboard::Scancode& keyPressed, 
                    const bool pressed) {

    if (pressed) {
        if (keyPressed == sf::Keyboard::Scancode::D) {
            states[sf::Keyboard::Scancode::D] = (states[sf::Keyboard::Scancode::A]) ? 2 : 1;
            states[sf::Keyboard::Scancode::A] = (states[sf::Keyboard::Scancode::A]) ? 1 : 0;

        } else if (keyPressed == sf::Keyboard::Scancode::A) {
            states[sf::Keyboard::Scancode::A] = (states[sf::Keyboard::Scancode::D]) ? 2 : 1;
            states[sf::Keyboard::Scancode::D] = (states[sf::Keyboard::Scancode::D]) ? 1 : 0;

        } else if (keyPressed == sf::Keyboard::Scancode::Right) {
            states[sf::Keyboard::Scancode::Right] = (states[sf::Keyboard::Scancode::Left]) ? 2 : 1;
            states[sf::Keyboard::Scancode::Left] = (states[sf::Keyboard::Scancode::Left]) ? 1 : 0;

        } else if (keyPressed == sf::Keyboard::Scancode::Left) {
            states[sf::Keyboard::Scancode::Left] = (states[sf::Keyboard::Scancode::Right]) ? 2 : 1;
            states[sf::Keyboard::Scancode::Right] = (states[sf::Keyboard::Scancode::Right]) ? 1 : 0;
        }

    } else {
        states[keyPressed] = 0;
    }
}

