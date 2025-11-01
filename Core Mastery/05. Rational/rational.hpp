#include <iostream>
#include <numeric>


class Rational {
    private:
        int _num;
        int _denum;

        int gcd(int a, int b)  {
            while (b != 0) {
                int t = b;
                b = a % b;
                a = t;
            }
            return a < 0 ? -a : a;
        } 

        void reduce_helper() { 
            int tmp = gcd(this->_num, this->_denum);
            this->_num /= tmp;
            this->_denum /= tmp;
        }

    public:
        // Constructors
        Rational () : _num(0), _denum(1) {}
        Rational (int num) : _num(num) , _denum(0) {}
        Rational (int num, int denum);

        // Move & Copy Constructor
        Rational (const Rational& oth) : _num(oth._num), _denum (oth._denum) {};
        Rational (Rational&& oth);

        // Assign operator
        Rational& operator= (Rational&& oth);
        Rational& operator=(const Rational& oth);

        // Destructor
        ~Rational () = default;

        // Unar operator
        Rational operator+() const;
        Rational  operator-() const;
        bool operator !() const;
        Rational& operator++();
        Rational& operator--();
        Rational operator++(int);
        Rational operator--(int);

        // Binary arithmetic operator
        Rational& operator+=(const Rational& oth);
        Rational& operator-=(const Rational& oth);
        Rational& operator*=(const Rational& oth);
        Rational& operator/=(const Rational& oth);

        // Binary arithmetic operators No-Member Functions
        friend Rational operator+(Rational rhs, const Rational& oth);
        friend Rational operator-(Rational rhs, const Rational& oth);
        friend Rational operator*(Rational rhs, const Rational& oth);
        friend Rational operator/(Rational rhs, const Rational& oth);

        // Comparison operators operators No-Member Functions
        friend bool operator==(const Rational& lhs, const Rational& rhs); 
        friend bool operator!=(const Rational& lhs, const Rational& rhs); 
        friend bool operator<(const Rational& lhs, const Rational& rhs); 
        friend bool operator>(const Rational& lhs, const Rational& rhs); 
        friend bool operator<=(const Rational& lhs, const Rational& rhs); 
        friend bool operator>=(const Rational& lhs, const Rational& rhs);

        // Stream operators No-Member Functions
        friend std::istream& operator>>(std::istream& is, Rational& r);
        friend std::ostream& operator<<(std::ostream& os, const Rational& r);

        // Getters
        int numerator() const noexcept { return _num; }
        int denominator() const noexcept { return _denum; }

        // Optional conversions Member Function
        explicit operator double() const {
            return this->_num / this->_denum;
        }
};