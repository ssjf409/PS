#include <iostream>
#include <vector>

using namespace std;



int main() {
    int n;
    cin >> n;
    int dp[n] = {0,};
    int wine[n] = {0,};

    for(int i = 0; i < n; i++) {
        cin >> wine[i];
    }
    dp[0] = wine[0];
    dp[1] = wine[0] + wine[1];
    dp[2] = max(max(dp[0] + wine[2], wine[1] + wine[2]), dp[1]);
    int result = dp[2];
    for(int i = 3; i < n; i++) {
        dp[i] = max(dp[i - 3] + wine[i - 1] + wine[i], dp[i - 2] + wine[i]);
        dp[i] = max(dp[i - 1], dp[i]);
        result = max(dp[i], result);
    }

    cout << result;

}