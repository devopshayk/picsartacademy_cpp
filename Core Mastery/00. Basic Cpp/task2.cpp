#include <iostream>
using namespace std;

    void swap(int& x, int& y);

    int main() {
        int a, b;
        
        cout << "Write two nums for swap: ";
        cin >> a >> b;

        cout << "Num 1 = " << a << ", Num 2 = " << b << endl;

        swap(a, b);

        cout << "Num 1 = " << a << ", Num 2 = " << b << endl;

        return 0;
    }

    void swap(int& x, int& y) {
        int tmp = x;
        x = y;
        y = tmp;
    }