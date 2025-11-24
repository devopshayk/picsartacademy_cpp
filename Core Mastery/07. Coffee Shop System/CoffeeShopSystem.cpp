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
////////// . ->
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

void Customer::placeOrder(Order* order) {
    currentOrder = order;
}

void Customer::payOrder() {
    if (balance < currentOrder->getTotalPrice()) {
        std::cout << "Your balance is few: " << std::endl;
        return;
    }

    balance -= currentOrder->getTotalPrice();
    
    currentOrder->markPaid();
}

void Customer::viewOrder() const {
    if(!currentOrder) {
        std::cout << "No active order: " << std::endl;
        return;
    }
 
    std::cout << name << "'s order: ";
    currentOrder->displayOrder();
}

void Customer::display() const {
    std::cout << "Name is: " << name << std::endl;
    std::cout << "Balance = " << balance << std::endl;

    if(currentOrder) {
        std::cout << "Current ID: " << currentOrder->getOrderId() << std::endl;
    }
    else std::cout << "No current order" << std::endl;
}



// ----> Barista <----

Barista::Barista(const std::string& newName) : name(newName) {}

std::string Barista::getName() const { return name; }
void Barista::setName(const std::string& newName) { name = newName; }

void Barista::prepareOrder(Order * order) {
    if(!order) {
        std::cout << "No order to prepare. " << std::endl;
        return;
    }

    order->markPrepared();
    std::cout << "Order #" << order->getOrderId() << "has been prepaired" << std::endl;
}

void Barista::greetCustomer() const {
    std::cout << name << "greets the customer and asks what they would like to order." << std::endl;
}



// ----> CoffeeShop <----


CoffeeShop::CoffeeShop(const std::string& name) : shopName(name) {}

std::string CoffeeShop::getName() const { return shopName; }
void CoffeeShop::setName(const std::string& newName) { shopName = newName; }


void CoffeeShop::addDrink(Drink* drink) {
    menu.push_back(drink);
}

void CoffeeShop::removeDrink(const std::string& drinkName) {
    for(int i = 0; i < menu.size(); i++) {
        if(menu[i]->getName() == drinkName) {
            menu.erase(menu.begin() + i);
            return;
        }
    }

    std::cout << "Drink not found. " << std::endl;
}

void CoffeeShop::showMenu() const {
    if(menu.size() == 0) {
        std::cout << "Menu is empty. " << std::endl;
        return;
    }
    
    for(Drink * drink : menu) {
        std::cout << "Drink Name: " << drink->getName() << std::endl;
        std::cout << "Drink Prince: " << drink->getPrice() << std::endl;

        switch(drink->getVolume()) {
            case Drink::Size::Small: std::cout << "Small"; break;
            case Drink::Size::Medium: std::cout << "Medium"; break;
            case Drink::Size::Big: std::cout << "Big"; break;
        }

        std::cout << std::endl;
    }
}

void CoffeeShop::hireBarista(Barista* barista) {
    
}
void CoffeeShop::fireBarista(Barista* barista) {}
void CoffeeShop::showBaristas() const {}
void CoffeeShop::addCustomerToQueue(Customer* customer) {}
void CoffeeShop::serveNextCustomer() {}
void CoffeeShop::showQueue() const {}
void CoffeeShop::constructMenu() {}
void CoffeeShop::displayShopInfo() const {}