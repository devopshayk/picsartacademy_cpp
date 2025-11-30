#pragma once
#include <iostream>


enum class Kind {
    Animal, Mammal, Bird, Reptile,
    Lion, Tiger, Elephant,
    Eagle, Parrot,
    Snake, Crocodile
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
        void PrintInfo() const;   
        void Feed();            
        Kind KindOf() const;
        int Id() const;

        Animal() : name{}, health(100), hunger{}, _kind(Kind::Animal), id(_nextId++) {};
        Animal(int healt, int hunger) : health{healt}, hunger{hunger} {};
        Animal(std::string name) : name{name} {};

        virtual ~Animal() = default;
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


class Lion : public Animal, public IWalk, public IVoice, public IFeedable {
public:
    Lion(const std::string& name);

    void Walk() override;
    void Voice() override;
    void Feed() override;
};