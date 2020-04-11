#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    long long dp[101] = {0,};

    dp[1] = 9;
    
    for(int i = 2; i <= N; i++) {
        dp[i] = 2 * (dp[i - 1] - 1) + 1;
    }

    cout << dp[N] % 1000000000;

    return 0;
}