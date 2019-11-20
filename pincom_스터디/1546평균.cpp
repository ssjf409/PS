#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;

    int sum = 0;
    int max = -1;
    int temp;

    for(int i = 0; i < N; i++) {
        cin >> temp;
        if(temp > max) {
            max = temp;
        }
        sum += temp;
    }

    cout << (double)sum / (double)max * 100.0 / (double)N;
    
    return 0;
}