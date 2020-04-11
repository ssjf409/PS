#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    int arr[N];
    int dp[N] = {0,};
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < N; i++) {
        if (dp[i] == 0)dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j]) {
                if (dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                }
            }
        }
    }

    cout << dp[N - 1];

    return 0;
}
