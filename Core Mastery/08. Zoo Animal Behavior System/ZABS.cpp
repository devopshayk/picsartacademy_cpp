#include "ZABS.hpp"
#include <iostream>
#include <string>
#include <vector>


void Animal::PrintInfo() const {
    std::cout << "Animal's name: " << name << std::endl;
    std::cout << "Animal's health: " << health << std::endl;
    std::cout << "Animal's hunger: " << hunger << std::endl;

    std::cout << "Kind is: ";
    switch(_kind) {
        case Kind::Animal: std::cout << "Animal"; break;
        case Kind::Mammal: std::cout << "Mammal"; break;
        case Kind::Bird: std::cout << "Bird"; break;
        case Kind::Reptile: std::cout << "Reptile"; break;
        case Kind::Lion: std::cout << "Lion"; break;
        case Kind::Tiger: std::cout << "Tiger"; break;
        case Kind::Elephant: std::cout << "Elephant"; break;
        case Kind::Eagle: std::cout << "Eagle"; break;
        case Kind::Parrot: std::cout << "Parrot"; break;
        case Kind::Snake: std::cout << "Snake"; break;
        case Kind::Crocodile: std::cout << "Crocodile"; break;

        default:
            std::cout << "Unkown" << std::endl;
    }

    std::cout << std::endl;
}

void Animal::Feed() {
    if(hunger > 0) {
        --hunger;

        if(health < 100) {
            ++health;
        }

        return;
    }

    else std::cout << "Animal is already full" << std::endl;
}

Kind Animal::KindOf() const {
    return _kind;
}

int Animal::_nextId = 1;

int Animal::Id() const {
    return id;
}

// <-----> Lion

Lion::Lion(const std::string& name) : Animal() {
    this->name = name;
    _kind = Kind::Lion;
}

void Lion::Walk()  {
    std::cout << "Lion is walk" << std::endl;
}

void Lion::Voice() {
    std::cout << "Lion is roars" << std::endl;
}

void Lion::Feed() {
    std::cout << "Lion eats meat." << std::endl;
    Animal::Feed();
}