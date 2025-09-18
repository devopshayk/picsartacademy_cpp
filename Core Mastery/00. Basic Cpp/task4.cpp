#include <iostream>
#include <vector>

using namespace std;

    int main() {
        int N;
        int average = 0, sum = 0;

        cout << "Write size for vector: ";
        cin >> N;
        
        cout << endl;

        vector<int> v(N);

        cout << "Write " << N << " elements for vector: ";
        for(int i = 0; i < N; i++) cin >> v[i];

        for(int i = 0; i < N; i++) sum += v[i];
        average = sum / N;

        cout << endl;

        cout << "Average: " << average << endl;
        cout << "Sum: " << sum << endl;

        return 0;
    }