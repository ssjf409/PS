#include <iostream>
#define LIMIT 1000000000

using namespace std;


int main() {
    int N;
    cin >> N;
    long long dp[10] = {0, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    long long temp[10] = {0,};
    

    for(int i = 1; i < N; i++) {
        for(int j = 0; j <= 9; j++) {
            if(j == 0) {
                temp[1] = (dp[0] + temp[1]) % LIMIT;
                continue;
            }
            if(j == 9) {
                temp[8] = (dp[9] + temp[8]) % LIMIT;
                continue;
            }
            temp[j - 1] = (dp[j] + temp[j - 1]) % LIMIT;
            temp[j + 1] = (dp[j] + temp[j + 1]) % LIMIT;
        }
        for(int j = 0; j < 10; j++) {
            dp[j] = temp[j];
            temp[j] = 0;
        }
    }

    long long sum = 0;
    for(int i = 0; i < 10; i++) {
        sum = (dp[i] + sum) % LIMIT;
    }

    cout << sum;


    return 0;
}