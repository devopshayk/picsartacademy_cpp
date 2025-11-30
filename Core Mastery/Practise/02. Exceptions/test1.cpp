#include <iostream>
#include <stdexcept>
#include <sstream>
#include <cmath>
#include <string>

class CalcLogicError : public std::logic_error {
public:
    using std::logic_error::logic_error;
};

class CalcRuntimeError : public std::runtime_error {
public:
    using std::runtime_error::runtime_error;
};

double calculate(double a, char op, double b) {
    switch (op) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        
        case '*':
        case 'x':
        case 'X':
            return a * b;

        case '/':
            if (b == 0.0) {
                throw CalcRuntimeError("Division by zero");
            }
            return a / b;

        case '^':   
            return std::pow(a, b);

        default:
            throw CalcLogicError("Unknown operator: " + std::string(1, op));
    }
}

int main() {
    std::cout << "Calculator\n";
    std::cout << "Format: a op b (example: 2 + 3)\n";
    std::cout << "Enter q to quit.\n\n";

    std::string line;

    while (true) {
        std::cout << "> ";
        if (!std::getline(std::cin, line)) {
            break;
        }

        if (line == "q" || line == "Q") {
            break;
        }

        try {
            std::stringstream ss(line);
            double a, b;
            char op;

            if (!(ss >> a >> op >> b)) {
                throw CalcLogicError("Invalid input format");
            }

            double result = calculate(a, op, b);
            std::cout << "Result: " << result << "\n";
        }
        catch (const CalcLogicError& e) {
            std::cout << "[LogicError] " << e.what() << "\n";
        }
        catch (const CalcRuntimeError& e) {
            std::cout << "[RuntimeError] " << e.what() << "\n";
        }
        catch (const std::exception& e) {
            std::cout << "[Exception] " << e.what() << "\n";
        }
    }

    std::cout << "Program finished.\n";
    return 0;
}


