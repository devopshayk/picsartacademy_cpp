#include "CoffeeShopSystem.hpp"
#include <iostream>
#include <string>
#include <vector>

//  ----> Drink <----

Drink::Drink(const std::string& name, Size volume, double price) : name(name), volume(volume), price(price) {}


std::string Drink::getName() const { return name; }    
Drink::Size Drink::getVolume() const { return volume; }
double Drink::getPrice() const { return price; }


void Drink::setName(const std::string& newName) { name = newName; }
void Drink::setVolume(Size newVolume) { volume = newVolume; }
void Drink::setPrice(double newPrice) { price = newPrice; }


void Drink::display() const {
    std::cout << "Name: " << getName() << std::endl;

    Drink::Size size = getVolume();
    switch (size) {
        case Drink::Size::Small:  std::cout << "Small"; break;
        case Drink::Size::Medium: std::cout << "Medium"; break;
        case Drink::Size::Big:    std::cout << "Big"; break;
    }

    std::cout << "Price: " << getPrice() << std::endl;
}


//  ----> Order <----

Order::Order() : orderId(0), totalPrice(0.0), isPrepared(false), isPaid(false) {}
Order::Order(int id) : orderId(id) {}


int Order::getOrderId() const { return orderId; }
double Order::getTotalPrice() const { return totalPrice; }
bool Order::getIsPrepared() const { return isPrepared; }
bool Order::getIsPaid() const { return isPaid; }


void Order::addDrink(const Drink& drink) {
    drinks.push_back(drink);
    calculateTotalPrice();
}

void Order::calculateTotalPrice() {
    totalPrice = 0.0;

    for(const Drink& d : drinks) {
        totalPrice += d.getPrice();
    }
}

void Order::removeDrink(int index) {
    if(index < 0 || index >= drinks.size()) {
        std::cout << "Invalid Index" << std::endl;
        return;
    }

    drinks.erase(drinks.begin() + index);
    calculateTotalPrice();
}

void Order::markPrepared() {
    isPrepared = true;
}

void Order::markPaid() {
    isPaid = true;
}

void Order::displayOrder() const {
    std::cout << "ID: " << orderId << std::endl;
    std::cout << "Price: " << totalPrice << std::endl;
    std::cout << "Prepared: " << (isPrepared ? "Yes" : "No") << std::endl;
    std::cout << "Paid: " << (isPaid ? "Yes" : "No") << std::endl;
    std::cout << "Drinks: " << std::endl;

    for(const Drink& d : drinks) {
        std::cout << d.getName() << " (";

        switch(d.getVolume()) {
            case Drink::Size::Small: std::cout << "Small"; break;
            case Drink::Size::Medium: std::cout << "Medium"; break;
            case Drink::Size::Big: std::cout << "Big"; break;
        }
        
        std::cout << ") " << d.getPrice() << "AMD" << std::endl;
    }
}


// ----> Customer <----

Customer::Customer(const std::string& name, double balance) : name(name), balance(balance) {}

std::string Customer::getName() const { return name; }
double Customer::getBalance() const { return balance; }
void Customer::setBalance(double newBalance) { balance = newBalance; }

