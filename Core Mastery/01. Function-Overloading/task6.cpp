#include <iostream>

    int sum(int a, int b);
    double sum(double a, double b);

    int main() {
        std::cout << "sum(3, 4) = " << sum(3, 4) << std::endl;
        std::cout << "sum(3.5, 2.5) = " << sum(3.5, 2.5) << std::endl;
        std::cout << "sum(3, 2.5) = " << sum(3, 2.5) << std::endl;

        return 0;
    }

    int sum(int a, int b) {
        return a + b;
    }

    double sum(double a, double b) {
        return a + b;
    }

    double sum(int a, double b) { 
        return a + b; 
    }

    /*

    Problem explanation:

    We have two overloaded functions:

    int sum(int a, int b);
    double sum(double a, double b);

    When we call sum(3, 2.5):

    - First argument: int (3)
    - Second argument: double (2.5)

    The compiler tries to choose the best overload:

    1) sum(int, int) → would require converting 2.5 (double) to int (possible but lossy)
    2) sum(double, double) → would require converting 3 (int) to double (safe)

    Both conversions are valid, but neither is clearly better.
    This creates an **ambiguous call**, so the compiler gives an error.

    Solutions:
    - Call sum(3.0, 2.5) to force double sum(double, double)
    - Add overloads for mixed types: sum(int, double) and sum(double, int)
    - Use static_cast to explicitly convert arguments
    
    */