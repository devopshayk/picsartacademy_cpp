#include "vector.hpp"
#include <iostream>
#include <utility> // For std::move
#include <iomanip> // For formatting

/**
 * @brief Prints the vector's size, capacity, and contents for easy debugging.
 * @param title A descriptive title for the test step.
 * @param v The MyVector object to inspect.
 */
void print_info(const std::string& title, const MyVector& v) {
    std::cout << "\n--- " << title << " ---" << std::endl;
    std::cout << " Size: " << v.getSize() 
              << ", Capacity: " << v.getCapacity() << std::endl;
    std::cout << " Data: ";
    v.print_vector();
}

/**
 * @brief Simple separator for visual clarity.
 */
void separator() {
    std::cout << "\n======================================================\n";
}

int main() {
    std::cout << "Starting MyVector Tests...\n";
    separator();

    // -------------------------------------------------------------------------
    // TEST 1: CONSTRUCTORS
    // -------------------------------------------------------------------------
    
    // Test 1.1: Capacity Constructor (Initial capacity 5)
    MyVector v1(5);
    print_info("1.1. Capacity Constructor (v1)", v1); 
    
    // Test 1.2: Initializer List Constructor
    MyVector v2 = {10, 20, 30, 40};
    print_info("1.2. Initializer List Constructor (v2)", v2);
    
    // Test 1.3: Size and Value Constructor
    MyVector v3(3, 99);
    print_info("1.3. Size/Value Constructor (v3)", v3);

    separator();

    // -------------------------------------------------------------------------
    // TEST 2: MUTATOR METHODS (push_back, pop_back)
    // -------------------------------------------------------------------------
    
    // Testing v1 (capacity 5, size 0)
    v1.push_back(1);
    v1.push_back(2);
    print_info("2.1. Push Back (v1)", v1); // Size 2, Capacity 5

    // Test reallocation (size 5 -> 10 or 8)
    v1.push_back(3);
    v1.push_back(4);
    v1.push_back(5); // Size 5, Capacity 5 (Full)
    v1.push_back(6); // Trigger reallocation (Capacity should increase)
    print_info("2.2. Push Back with Reallocation (v1)", v1); // Size 6, Capacity > 5
    
    v1.pop_back();
    v1.pop_back();
    print_info("2.3. Pop Back (v1)", v1); // Size 4

    separator();

    // -------------------------------------------------------------------------
    // TEST 3: COPY SEMANTICS
    // -------------------------------------------------------------------------
    
    // Test 3.1: Copy Constructor
    MyVector v_copy = v1;
    print_info("3.1. Copy Constructor (v_copy from v1)", v_copy);
    
    v_copy.push_back(888);
    std::cout << "\nChecking independence after copy:" << std::endl;
    print_info("v1 (Original)", v1);         // Should remain unchanged
    print_info("v_copy (Modified)", v_copy); // Should have 888

    // Test 3.2: Copy Assignment Operator
    MyVector v_assign(1);
    v_assign.push_back(100);
    print_info("v_assign (Before Copy Assignment)", v_assign);
    
    v_assign = v2; // Assignment from {10, 20, 30, 40}
    print_info("3.2. Copy Assignment (v_assign = v2)", v_assign);
    
    separator();

    // -------------------------------------------------------------------------
    // TEST 4: MOVE SEMANTICS
    // -------------------------------------------------------------------------

    // Test 4.1: Move Constructor
    // v_move receives resources from v3 (which is {99, 99, 99})
    MyVector v_move = std::move(v3);
    
    print_info("4.1. Move Constructor (v_move receives resources)", v_move);
    std::cout << "\nChecking source state (v3) after Move Constructor:" << std::endl;
    print_info("v3 (Source)", v3); // MUST be size 0, capacity 0, data nullptr
    
    // Test 4.2: Move Assignment Operator
    // v_assign_move has old data, v2 is the source
    MyVector v_assign_move = {5, 6, 7};
    print_info("v_assign_move (Before Move Assignment)", v_assign_move);

    v_assign_move = std::move(v2); // Assignment from v2 (which is {10, 20, 30, 40})

    print_info("4.2. Move Assignment (v_assign_move = std::move(v2))", v_assign_move);
    std::cout << "\nChecking source state (v2) after Move Assignment:" << std::endl;
    print_info("v2 (Source)", v2); // MUST be size 0, capacity 0, data nullptr

    separator();

    // -------------------------------------------------------------------------
    // TEST 5: INSERT AND ERASE
    // -------------------------------------------------------------------------
    
    MyVector v_op = {1, 2, 3, 4, 5};
    print_info("5.0. Base Vector (v_op)", v_op);

    // Test 5.1: Insert (middle, value 999)
    v_op.insert(2, 999);
    print_info("5.1. Insert (index 2, val 999)", v_op); // Should be {1, 2, 999, 3, 4, 5}

    // Test 5.2: Insert (end, default 0)
    v_op.insert(v_op.getSize()); // Insert at the end
    print_info("5.2. Insert (at end, default 0)", v_op); // Should be {..., 5, 0}

    // Test 5.3: Erase (middle)
    v_op.erase(3); // Erase the '3' (now at index 3)
    print_info("5.3. Erase (index 3)", v_op); // Should be {1, 2, 999, 4, 5, 0}

    // Test 5.4: Erase (first element)
    v_op.erase(0); 
    print_info("5.4. Erase (index 0)", v_op); // Should be {2, 999, 4, 5, 0}

    // Test 5.5: Clear
    v_op.clear();
    print_info("5.5. Clear", v_op); // Size 0, Capacity preserved

    separator();
    std::cout << "All tests completed successfully (check console output)." << std::endl;

    return 0;
}