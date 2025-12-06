#include "ZABS.hpp"

int Animal::_nextId = 1;

 Animal::Animal(const std::string& name)
    : name(name), health(100), hunger(0), _kind(Kind::Animal), id(_nextId++) {
    std::cout << "Animal ctor: " << name << std::endl;
}

Animal::~Animal() {}

void Animal::PrintInfo() const {
    std::cout << "ID: " << id << " | Name: " << name
              << " | Health: " << health
              << " | Hunger: " << hunger
              << " | Kind: " << static_cast<int>(_kind)
              << std::endl;
}

void Animal::Feed() {
    if (hunger > 0) hunger--;
    if (health < 100) health++;
}

Kind Animal::KindOf() const { return _kind; }
int Animal::Id() const { return id; }


Mammal::Mammal(const std::string& name) : Animal(name), warmBlooded(true) {
    _kind = Kind::Mammal;
}

Mammal::~Mammal() {}

void Mammal::MakeSound() {
    std::cout << "Generic mammal sound\n";
}


Bird::Bird(const std::string& name, double ws) : Animal(name), wingSpan(ws) {
    _kind = Kind::Bird;
}

Bird::~Bird() {}

void Bird::FlyGeneric() {
    std::cout << "Bird is flying\n";
}


Reptile::Reptile(const std::string& name) : Animal(name), coldBlooded(true) {
    _kind = Kind::Reptile;
}

Reptile::~Reptile() {}

void Reptile::Sunbathe() {
    std::cout << "Reptile is sunbathing\n";
}


Lion::Lion(const std::string& name, int power)
    : Mammal(name), roarPower(power) {
    _kind = Kind::Lion;
}

void Lion::Roar() {
    std::cout << "Lion roars with power " << roarPower << std::endl;
}

void Lion::Walk() { std::cout << "Lion walks\n"; }
void Lion::Voice() { Roar(); }
void Lion::Feed() { std::cout << "Lion eats meat\n"; Animal::Feed(); }


Tiger::Tiger(const std::string& name, double jump)
    : Mammal(name), jumpHeight(jump) {
    _kind = Kind::Tiger;
}

void Tiger::Jump() {
    std::cout << "Tiger jumps " << jumpHeight << " meters\n";
}

void Tiger::Walk() { std::cout << "Tiger walks\n"; }
void Tiger::Voice() { std::cout << "Tiger roars\n"; }
void Tiger::Feed() { std::cout << "Tiger eats meat\n"; Animal::Feed(); }


Elephant::Elephant(const std::string& name, double trunk)
    : Mammal(name), trunkLength(trunk) {
    _kind = Kind::Elephant;
}

void Elephant::UseTrunk() {
    std::cout << "Elephant uses trunk\n";
}

void Elephant::Walk() { std::cout << "Elephant walks\n"; }
void Elephant::Voice() { std::cout << "Elephant trumpets\n"; }
void Elephant::Feed() { std::cout << "Elephant eats plants\n"; Animal::Feed(); }


Eagle::Eagle(const std::string& name, double range)
    : Bird(name, 2.5), visionRange(range) {
    _kind = Kind::Eagle;
}

void Eagle::Soar() { std::cout << "Eagle soars\n"; }
void Eagle::Fly() { Soar(); }
void Eagle::Walk() { std::cout << "Eagle walks\n"; }
void Eagle::Voice() { std::cout << "Eagle screeches\n"; }
void Eagle::Feed() { std::cout << "Eagle eats fish\n"; Animal::Feed(); }


Parrot::Parrot(const std::string& name) : Bird(name, 0.5) {
    _kind = Kind::Parrot;
}

void Parrot::Speak() { std::cout << "Parrot speaks words\n"; }
void Parrot::Fly() { std::cout << "Parrot flies\n"; }
void Parrot::Walk() { std::cout << "Parrot walks\n"; }
void Parrot::Voice() { Speak(); }
void Parrot::Feed() { std::cout << "Parrot eats grains\n"; Animal::Feed(); }


Snake::Snake(const std::string& name, bool poison)
    : Reptile(name), poisonous(poison) {
    _kind = Kind::Snake;
}

void Snake::Hiss() { std::cout << "Snake hisses\n"; }
void Snake::Walk() { std::cout << "Snake crawls\n"; }
void Snake::Voice() { Hiss(); }
void Snake::Feed() { std::cout << "Snake eats mouse\n"; Animal::Feed(); }


Crocodile::Crocodile(const std::string& name, int force)
    : Reptile(name), biteForce(force) {
    _kind = Kind::Crocodile;
}

void Crocodile::Snap() { std::cout << "Crocodile snaps with force " << biteForce << '\n'; }
void Crocodile::Walk() { std::cout << "Crocodile walks\n"; }
void Crocodile::Swim() { std::cout << "Crocodile swims\n"; }
void Crocodile::Voice() { std::cout << "Crocodile growls\n"; }
void Crocodile::Feed() { std::cout << "Crocodile eats meat\n"; Animal::Feed(); }