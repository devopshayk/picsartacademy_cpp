#include "ZABS.hpp"
#include <vector>
#include <iostream>

int main() {
    std::cout << "\n===== ZOO SYSTEM START =====\n\n";

    // ===== СОЗДАНИЕ ЖИВОТНЫХ =====
    Lion simba("Simba", 9);
    Tiger tony("Tony", 6.5);
    Elephant dumbo("Dumbo", 2.3);

    Eagle aquila("Aquila", 1200);
    Parrot kesha("Kesha");

    Snake sly("Sly", true);
    Crocodile gena("Gena", 10);

    // ===== ВЕКТОР БАЗОВЫХ УКАЗАТЕЛЕЙ =====
    std::vector<Animal*> animals = {
        &simba, &tony, &dumbo,
        &aquila, &kesha,
        &sly, &gena
    };

    // ===== ПЕРВЫЙ ОБЗОР =====
    std::cout << "\n===== INITIAL STATE =====\n";
    for (Animal* a : animals)
        a->PrintInfo();

    // ===== МАССОВОЕ КОРМЛЕНИЕ (3 РАЗА) =====
    std::cout << "\n===== MASS FEEDING x3 =====\n";
    for (int i = 1; i <= 3; ++i) {
        std::cout << "\n-- FEED ROUND " << i << " --\n";
        for (Animal* a : animals)
            a->Feed();
    }

    // ===== СОСТОЯНИЕ ПОСЛЕ КОРМЁЖКИ =====
    std::cout << "\n===== STATE AFTER FEEDING =====\n";
    for (Animal* a : animals)
        a->PrintInfo();

    // ===== СПЕЦ-ДЕЙСТВИЯ ПО ТИПАМ =====
    std::cout << "\n===== SPECIAL ACTIONS BY TYPE =====\n";

    for (Animal* a : animals) {
        switch (a->KindOf()) {

        case Kind::Lion: {
            auto* lion = static_cast<Lion*>(a);
            lion->Roar();
            lion->Walk();
            break;
        }

        case Kind::Tiger: {
            auto* tiger = static_cast<Tiger*>(a);
            tiger->Jump();
            tiger->Walk();
            break;
        }

        case Kind::Elephant: {
            auto* elephant = static_cast<Elephant*>(a);
            elephant->UseTrunk();
            elephant->Walk();
            break;
        }

        case Kind::Eagle: {
            auto* eagle = static_cast<Eagle*>(a);
            eagle->Fly();
            eagle->Soar();
            eagle->Walk();
            break;
        }

        case Kind::Parrot: {
            auto* parrot = static_cast<Parrot*>(a);
            parrot->Speak();
            parrot->Fly();
            parrot->Walk();
            break;
        }

        case Kind::Snake: {
            auto* snake = static_cast<Snake*>(a);
            snake->Hiss();
            snake->Walk();
            break;
        }

        case Kind::Crocodile: {
            auto* croc = static_cast<Crocodile*>(a);
            croc->Swim();
            croc->Snap();
            croc->Walk();
            break;
        }

        default:
            break;
        }
    }

    // ===== СТЕСС-ТЕСТ КОРМЛЕНИЯ =====
    std::cout << "\n===== STRESS FEED TEST (10 ROUNDS) =====\n";
    for (int i = 0; i < 10; ++i)
        for (Animal* a : animals)
            a->Feed();

    // ===== ФИНАЛЬНОЕ СОСТОЯНИЕ =====
    std::cout << "\n===== FINAL STATE =====\n";
    for (Animal* a : animals)
        a->PrintInfo();

    std::cout << "\n===== ZOO SYSTEM SHUTDOWN =====\n";
    return 0;
}