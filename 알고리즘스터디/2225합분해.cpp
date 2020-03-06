#include <iostream>
#define DIVIDER 1000000000

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    long long arr[N + 1];

    for(int i = 0; i <= N; i++) {
        arr[i] = 1;
    }

    for(int i = 1; i < K; i++) {
        long long sum = 0;
        for(int j = 0; j <= N; j++) {
            sum += arr[j];
            arr[j] = sum % DIVIDER;
        }
    }
    cout << arr[N] % DIVIDER;
    return 0;
}