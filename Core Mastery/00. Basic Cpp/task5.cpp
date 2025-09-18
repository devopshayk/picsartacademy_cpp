#include <iostream>
#include <vector>

using namespace std;

    int main() {
        int N;

        cout << "Write size for vector: ";
        cin >> N;

        vector<int> v(N);

        cout << endl;

        cout << "Write " << N << " elements for vector: ";
        for(int i = 0; i < N; i++) cin >> v[i];

        int max = v[0], min = v[0];

        for(int i = 0; i < N; i++) {
            if(min > v[i]) min = v[i];
            else if(max < v[i]) max = v[i];
        }

        cout << endl;

        cout << "Max element in vector = " << max << endl;
        cout << "Min element in vector = " << min << endl;

        return 0;
    }