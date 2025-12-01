#pragma once
#include <iostream>
#include <vector>
#include <string>


enum class Kind {
    Animal, Mammal, Bird, Reptile,
    Lion, Tiger, Elephant,
    Eagle, Parrot,
    Snake, Crocodile
};


struct IFly {
    virtual void Fly() = 0;
    virtual ~IFly() = default;
};

struct ISwim {
    virtual void Swim() = 0;
    virtual ~ISwim() = default;
};

struct IWalk {
    virtual void Walk() = 0;
    virtual ~IWalk() = default;
};

struct IVoice {
    virtual void Voice() = 0;
    virtual ~IVoice() = default;
};

struct IFeedable {
    virtual void Feed() = 0;
    virtual ~IFeedable() = default;
};


class Animal {
protected:
    std::string name;
    int health;
    int hunger;
    Kind _kind;
    static int _nextId;
    int id;

public:
    Animal(const std::string& name);

    void PrintInfo() const;
    void Feed();
    Kind KindOf() const;
    int Id() const;

    virtual ~Animal() = 0;   
};


class Mammal : public Animal {
protected:
    bool warmBlooded;

public:
    Mammal(const std::string& name);
    virtual void MakeSound();
    virtual ~Mammal() = 0;
};

class Bird : public Animal {
protected:
    double wingSpan;

public:
    Bird(const std::string& name, double wingSpan);
    virtual void FlyGeneric();
    virtual ~Bird() = 0;
};

class Reptile : public Animal {
protected:
    bool coldBlooded;

public:
    Reptile(const std::string& name);
    virtual void Sunbathe();
    virtual ~Reptile() = 0;
};


class Lion : public Mammal, public IWalk, public IVoice, public IFeedable {
    int roarPower;
public:
    Lion(const std::string& name, int power);
    void Roar();
    void Walk() override;
    void Voice() override;
    void Feed() override;
};

class Tiger : public Mammal, public IWalk, public IVoice, public IFeedable {
    double jumpHeight;
public:
    Tiger(const std::string& name, double jump);
    void Jump();
    void Walk() override;
    void Voice() override;
    void Feed() override;
};

class Elephant : public Mammal, public IWalk, public IVoice, public IFeedable {
    double trunkLength;
public:
    Elephant(const std::string& name, double trunk);
    void UseTrunk();
    void Walk() override;
    void Voice() override;
    void Feed() override;
};


class Eagle : public Bird, public IFly, public IWalk, public IVoice, public IFeedable {
    double visionRange;
public:
    Eagle(const std::string& name, double range);
    void Soar();
    void Fly() override;
    void Walk() override;
    void Voice() override;
    void Feed() override;
};

class Parrot : public Bird, public IFly, public IWalk, public IVoice, public IFeedable {
    std::vector<std::string> vocabulary;
public:
    Parrot(const std::string& name);
    void Speak();
    void Fly() override;
    void Walk() override;
    void Voice() override;
    void Feed() override;
};


class Snake : public Reptile, public IWalk, public IVoice, public IFeedable {
    bool poisonous;
public:
    Snake(const std::string& name, bool poison);
    void Hiss();
    void Walk() override;
    void Voice() override;
    void Feed() override;
};

class Crocodile : public Reptile, public IWalk, public ISwim, public IVoice, public IFeedable {
    int biteForce;
public:
    Crocodile(const std::string& name, int force);
    void Snap();
    void Walk() override;
    void Swim() override;
    void Voice() override;
    void Feed() override;
};