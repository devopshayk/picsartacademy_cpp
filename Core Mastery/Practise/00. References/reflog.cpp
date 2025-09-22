#include <iostream>
#include <array>

using namespace std;

    int main() {
        int arr[] = {1, 2, 3, 4, 5};

        array<char, 50> my = {"Hello"};

        for(char e : my) {
            cout << e << endl;
        }
    }