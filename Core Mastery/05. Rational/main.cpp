#include <iostream>
#include "rational.hpp"

int main() {
    Rational a(3, 4);
    Rational b(5, 6);
    Rational c = a + b;
    Rational d = a - b;
    Rational e = a * b;
    Rational f = a / b;

    std::cout << "a = " << a << "\n";
    std::cout << "b = " << b << "\n";
    std::cout << "c = a + b = " << c << "\n";
    std::cout << "d = a - b = " << d << "\n";
    std::cout << "e = a * b = " << e << "\n";
    std::cout << "f = a / b = " << f << "\n\n";

    Rational g = c;
    Rational h(std::move(d));
    Rational i;
    i = e;
    Rational j;
    j = std::move(f);

    std::cout << "g (copy of c): " << g << "\n";
    std::cout << "h (moved from d): " << h << "\n";
    std::cout << "i (assigned from e): " << i << "\n";
    std::cout << "j (move-assigned from f): " << j << "\n\n";

    Rational k(7, 8);
    k += Rational(1, 8);
    k -= Rational(1, 4);
    k *= Rational(3, 2);
    k /= Rational(5, 3);

    std::cout << "k after +=, -=, *=, /=: " << k << "\n\n";

    if (a == Rational(3, 4)) std::cout << "a == 3/4\n";
    if (a != b) std::cout << "a != b\n";
    if (a < b) std::cout << "a < b\n";
    if (b > a) std::cout << "b > a\n";
    if (a <= a) std::cout << "a <= a\n";
    if (b >= a) std::cout << "b >= a\n\n";

    std::cout << "Unary +a: " << (+a) << "\n";
    std::cout << "Unary -a: " << (-a) << "\n\n";

    Rational m;
    std::cout << "Enter rational (num/denum): ";
    std::cin >> m;
    std::cout << "You entered: " << m << "\n\n";

    Rational x(1, 2);
    Rational y = ++x;
    Rational z = x++;
    std::cout << "After ++x: " << y << " , after x++: " << z << " , now x = " << x << "\n";

    return 0;
}
