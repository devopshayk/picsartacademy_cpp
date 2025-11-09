#include <iostream>
#include "sll.hpp"

void section(const std::string& title) {
    std::cout << "\n===== " << title << " =====\n";
}

int main() {
    // 1. Testing Constructors
    section("Constructors");

    SingleList lst1;
    std::cout << "Default constructor (lst1): " << lst1 << "\n";

    SingleList lst2(5, 3);
    std::cout << "Param constructor (lst2, 3 elements of 5): " << lst2 << "\n";

    SingleList lst3 = {1, 2, 3, 4};
    std::cout << "Initializer list constructor (lst3): " << lst3 << "\n";

    SingleList lst4(lst3);
    std::cout << "Copy constructor (lst4 copy of lst3): " << lst4 << "\n";

    SingleList lst5(std::move(lst4));
    std::cout << "Move constructor (lst5 moved from lst4): " << lst5 << "\n";
    std::cout << "After move, lst4: " << lst4 << "\n";

    // 2. Testing Assignment Operators
    section("Assignment Operators");

    lst1 = lst2;
    std::cout << "Copy assignment (lst1 = lst2): " << lst1 << "\n";

    lst4 = std::move(lst3);
    std::cout << "Move assignment (lst4 = move(lst3)): " << lst4 << "\n";
    std::cout << "After move, lst3: " << lst3 << "\n";

    // 3. Testing push/pop and size
    section("Push/Pop and size");

    SingleList lst6;
    lst6.push_front(10);
    lst6.push_front(20);
    lst6.push_back(30);
    std::cout << "After push front/back (lst6): " << lst6 << " (Size: " << lst6.size() << ")\n";

    lst6.pop_front();
    lst6.pop_back();
    std::cout << "After pop front/back (lst6): " << lst6 << " (Size: " << lst6.size() << ")\n";

    // 4. Testing operators +, +=
    section("Operator + and +=");

    SingleList lst7 = {1, 2, 3};
    SingleList lst8 = {4, 5};
    SingleList lst9 = lst7 + lst8;
    std::cout << "lst9 (lst7 + lst8): " << lst9 << "\n";

    lst7 += lst8;
    std::cout << "After lst7 += lst8: " << lst7 << "\n";

    // 5. Testing operator[]
    section("Operator []");

    std::cout << "lst9[2] = " << lst9[2] << "\n";
    lst9[2] = 99;
    std::cout << "After modification, lst9: " << lst9 << "\n";

    // 6. Testing comparison
    section("Comparison operators");

    SingleList lst10 = {1, 2, 3, 4};
    std::cout << "lst10 == lst9? " << (lst10 == lst9 ? "Yes" : "No") << "\n";
    lst9[3] = 4;
    std::cout << "After change, lst10 == lst9? " << (lst10 == lst9 ? "Yes" : "No") << "\n";

    // 7. Testing ++ and --
    section("Operators ++ and --");

    SingleList lst11 = {7, 8};
    std::cout << "Original lst11: " << lst11 << "\n";

    ++lst11;
    std::cout << "After prefix ++: " << lst11 << "\n";

    lst11++;
    std::cout << "After postfix ++: " << lst11 << "\n";

    --lst11;
    std::cout << "After prefix --: " << lst11 << "\n";

    lst11--;
    std::cout << "After postfix --: " << lst11 << "\n";

    // 8. Testing ! and conversion to bool
    section("Operator ! and bool conversion");

    SingleList lst12;
    std::cout << "Empty lst12, !lst12: " << (!lst12 ? "true" : "false") << "\n";
    lst12.push_back(42);
    std::cout << "After push, lst12: " << lst12 << ", bool(lst12): " << (lst12 ? "true" : "false") << "\n";

    // 9. Testing I/O operators
    section("I/O Operators");

    SingleList lst13;
    std::cout << "Enter number of elements followed by the elements: ";
    std::cin >> lst13;
    std::cout << "You entered: " << lst13 << "\n";

    // 10. Testing clear and copy
    section("clear() and copy()");

    lst13.clear();
    std::cout << "After clear(), lst13: " << lst13 << "\n";

    lst13.copy(lst2);
    std::cout << "After lst13.copy(lst2): " << lst13 << "\n";

    return 0;
}
