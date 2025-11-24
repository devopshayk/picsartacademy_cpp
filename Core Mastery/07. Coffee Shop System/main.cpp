#include "CoffeeShopSystem.hpp"
#include <iostream>

int main() {
    CoffeeShop shop("Hayk's Coffee");

    std::cout << "\n=== Constructing Menu ===\n";
    shop.constructMenu();
    shop.showMenu();

    std::cout << "\n=== Hiring Baristas ===\n";
    Barista* b1 = new Barista("Armen");
    Barista* b2 = new Barista("Maria");
    shop.hireBarista(b1);
    shop.hireBarista(b2);
    shop.showBaristas();

    std::cout << "\n=== Firing Barista (existing) ===\n";
    shop.fireBarista(b2);
    shop.showBaristas();

    std::cout << "\n=== Firing Barista (not existing) ===\n";
    shop.fireBarista(b2); 

    std::cout << "\n=== Creating Customers ===\n";
    Customer* c1 = new Customer("Hayk", 5000);
    Customer* c2 = new Customer("Narek", 2000);
    Customer* c3 = new Customer("Ani", 100);

    std::cout << "\n=== Adding Customers to Queue ===\n";
    shop.addCustomerToQueue(c1);
    shop.addCustomerToQueue(c2);
    shop.addCustomerToQueue(c3);
    shop.showQueue();

    std::cout << "\n=== Customers Place Orders ===\n";

    // Orders
    Order* o1 = new Order(1);
    Order* o2 = new Order(2);
    Order* o3 = new Order(3);

    // Manually create drinks (no getMenu used)
    Drink latte("Latte", Drink::Size::Medium, 1500);
    Drink espresso("Espresso", Drink::Size::Small, 800);
    Drink americano("Americano", Drink::Size::Medium, 1200);
    Drink mocha("Mocha", Drink::Size::Big, 1800);

    // Add drinks to orders
    o1->addDrink(latte);
    o1->addDrink(espresso);
    c1->placeOrder(o1);

    o2->addDrink(americano);
    c2->placeOrder(o2);

    o3->addDrink(mocha);
    c3->placeOrder(o3);

    c1->viewOrder();
    c2->viewOrder();
    c3->viewOrder();

    std::cout << "\n=== Serving Customers ===\n";
    shop.serveNextCustomer(); 
    shop.serveNextCustomer(); 
    shop.serveNextCustomer(); 
    shop.serveNextCustomer(); // queue empty

    std::cout << "\n=== Final Shop Info ===\n";
    shop.displayShopInfo();

    return 0;
}
