#include <iostream>

    void show(long x);
    void show(float x);

    int main() {
        show(5l);
        // show(5.0);  // may cause ambiguity
        show(5.0f);

        return 0;
    }

    void show(long x) {
        std::cout << "Long: " << x << std::endl;
    }

    void show(float x) {
        std::cout << "Float: " << x << std::endl;
    }

    /*
    
    Explanation:

    We have two overloaded functions:
        void show(long x);
        void show(float x);

    1) show(5l)
    - The literal '5l' is of type long.
    - Calls show(long) directly.

    2) show(5.0f)
    - The literal '5.0f' is of type float.
    - Calls show(float) directly.

    3) show(5.0)  // commented out
    - The literal '5.0' is of type double.
    - The compiler sees two possible conversions:
        double → long
        double → float
    - Both conversions are valid, but neither is better.
    - This creates an ambiguous call, which causes a compilation error if uncommented.

    Solution options:
    - Use a float literal (5.0f) or long literal (5l) to match a specific overload.
    - Add a separate overload for double if you want to handle double literals.
    
    */