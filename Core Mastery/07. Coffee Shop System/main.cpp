#include "CoffeeShopSystem.hpp"
#include <iostream>

int main() {
    std::cout << "\n========== STARTING MEGA-STRESS TEST ==========\n";

    CoffeeShop shop("Hayk's Coffee");

    std::cout << "\n=== TEST 1: Display info BEFORE menu, baristas, customers ===\n";
    shop.displayShopInfo();

    std::cout << "\n=== TEST 2: Constructing default menu ===\n";
    shop.constructMenu();
    shop.showMenu();

    std::cout << "\n=== TEST 3: Removing existing and non-existing drinks ===\n";
    shop.removeDrink("Latte");
    shop.removeDrink("NON_EXISTENT_DRINK");

    std::cout << "\n=== TEST 4: Hiring multiple baristas ===\n";
    Barista* b1 = new Barista("Armen");
    Barista* b2 = new Barista("Nane");
    Barista* b3 = new Barista("Karen");
    shop.hireBarista(b1);
    shop.hireBarista(b2);
    shop.hireBarista(b3);
    shop.showBaristas();

    std::cout << "\n=== TEST 5: Firing baristas correctly and incorrectly ===\n";
    shop.fireBarista(b2);
    shop.fireBarista(b2);
    shop.fireBarista(nullptr);

    std::cout << "\n=== TEST 6: Creating customers with different balances ===\n";
    Customer* c1 = new Customer("Hayk", 5000);
    Customer* c2 = new Customer("Ani", 1500);
    Customer* c3 = new Customer("Narek", 0);
    Customer* c4 = new Customer("EmptyOrder", 3000);
    Customer* c5 = nullptr;

    std::cout << "\n=== TEST 7: Adding customers to queue ===\n";
    shop.addCustomerToQueue(c1);
    shop.addCustomerToQueue(c2);
    shop.addCustomerToQueue(c3);
    shop.addCustomerToQueue(c4);
    shop.addCustomerToQueue(c5);
    shop.showQueue();

    std::cout << "\n=== TEST 8: Creating orders and placing them ===\n";
    Order* o1 = new Order(101);
    Order* o2 = new Order(102);
    Order* o3 = new Order(103);
    Order* o4 = new Order(104);

    Drink espresso("Espresso", Drink::Size::Small, 800);
    Drink latte("Latte", Drink::Size::Medium, 1500);
    Drink mocha("Mocha", Drink::Size::Big, 1800);

    o1->addDrink(espresso);
    o1->addDrink(latte);
    c1->placeOrder(o1);

    o2->addDrink(mocha);
    c2->placeOrder(o2);

    o3->addDrink(espresso);
    c3->placeOrder(o3);

    // c4 has NO order on purpose

    std::cout << "\nOrder c1:\n";
    c1->viewOrder();
    std::cout << "\nOrder c2:\n";
    c2->viewOrder();
    std::cout << "\nOrder c3:\n";
    c3->viewOrder();
    std::cout << "\nOrder c4:\n";
    c4->viewOrder();

    std::cout << "\n=== TEST 9: Serving queue under all scenarios ===\n";
    shop.serveNextCustomer(); // c1 OK
    shop.serveNextCustomer(); // c2 OK
    shop.serveNextCustomer(); // c3 not enough balance
    shop.serveNextCustomer(); // c4 has NO order
    shop.serveNextCustomer(); // queue empty

    std::cout << "\n=== TEST 10: Display final shop info ===\n";
    shop.displayShopInfo();

    std::cout << "\n========== MEGA-STRESS TEST COMPLETE ==========\n";

    return 0;
}