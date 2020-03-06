#include <iostream>
#include <vector>

using namespace std;


int main() {
    int N;
    int k;
    
    cin >> N;

    vector<int> passenger(N + 1, 0);
    vector<int> sum(N + 1, 0);
    vector<vector<int>> dp(4, vector<int> (N + 1, 0));

    for(int i = 1; i <= N; i++) {
        cin >> passenger[i];
        sum[i] = sum[i - 1] + passenger[i];
    }
    cin >> k;

    for(int i = 1; i <= 3; i++) {
        for(int j = i * k; j <= N; j++) {
            if(i == 1) {
                dp[i][j] = max(dp[i][j - 1], sum[j] - sum[j - k]);
            } else {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j - k] + sum[j] - sum[j - k]);
            }
        }
    }

    // for(int i = 0; i <= 3; i++) {
    //     for(int j = 0; j <= N; j++) {
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    cout << dp[3][N];

    return 0;
}