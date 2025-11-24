#pragma once
#include <string>
#include <vector>


class CoffeeShop {
    private:
        std::string shopName;
        std::vector<Drink*> menu;
        std::vector<Barista*> baristas; 
        std::vector<Customer*> queue;   

    public:
        CoffeeShop() = default;
        CoffeeShop(const std::string& name);

        std::string getName() const;
        void setName(const std::string& newName);

        void addDrink(Drink* drink);
        void removeDrink(const std::string& drinkName);
        void showMenu() const;

        void hireBarista(Barista* barista);
        void fireBarista(Barista* barista);
        void showBaristas() const;

        void addCustomerToQueue(Customer* customer);
        void serveNextCustomer();
        void showQueue() const;
        void constructMenu();

        void displayShopInfo() const;
};



class Customer {
    private:
        std::string name;
        double balance;
        Order* currentOrder; 

    public:
        Customer() = default;
        Customer(const std::string& name, double balance);


        std::string getName() const;
        double getBalance() const;
        Order* getCurrentOrder() const;
        void setBalance(double newBalance);

        void placeOrder(Order* order);
        void payOrder();
        void viewOrder() const;

        void display() const;
};


class Order {
    private:
        int orderId;
        std::vector<Drink> drinks;
        double totalPrice;
        bool isPrepared;
        bool isPaid;

    public:
        Order();
        Order(int id);

        int getOrderId() const;
        double getTotalPrice() const;
        bool getIsPrepared() const;
        bool getIsPaid() const;


        void addDrink(const Drink& drink);
        void removeDrink(int index);
        void calculateTotalPrice();


        void markPrepared();
        void markPaid();

        void displayOrder() const;
};



class Drink {
    public:
        enum class Size { Small, Medium, Big };

    private:
        std::string name;
        Size volume;
        double price;

    public:
        Drink() = default;
        Drink(const std::string& name, Size volume, double price);

        std::string getName() const;
        Size getVolume() const;
        double getPrice() const;

        void setName(const std::string& newName);
        void setVolume(Size newVolume);
        void setPrice(double newPrice);

        void display() const;
};



class Barista {
    private:
        std::string name;

    public:
        Barista() = default;
        Barista(const std::string& name);

        std::string getName() const;
        void setName(const std::string& newName);

        void prepareOrder(Order* order); 
        void greetCustomer() const;
};