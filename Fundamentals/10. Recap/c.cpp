#include <iostream>
#include <vector>
using namespace std;

int main()

{

    // initialize a vector

    vector<int> v1 = { 10, 20, 30, 40 }; 

    // declare an iterator

    vector<int>::iterator itr;

    // access vector elements without iterator

    cout << "Traversing without iterator : ";

    for (int j = 0; j < 4; ++j) {

        cout << v1[j] << " ";

    }

    cout << "\n";

    // access vector elements using an iterator

    cout << "Traversing using iterator ";

    for (itr = v1.begin(); itr != v1.end(); ++itr) {

        cout << *itr << " ";

    }

    cout << "\n\n";

    // insert an element into the vector

    v1.push_back(50);

    // access vector elements without iterator

    cout << "Traversing without iterator : ";

    for (int j = 0; j < 5; ++j) {

        cout << v1[j] << " ";

    }

    cout << "\n";

    // access vector elements using an iterator

    cout << "Traversing using iterator ";

    for (itr = v1.begin(); itr != v1.end(); ++itr) {

        cout << *itr << " ";

    }

    cout << "\n\n";

    return 0;

}