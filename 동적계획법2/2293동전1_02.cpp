#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;


int main() {
    int n, k;
    cin >> n >> k;

    vector<int> coins(n , 0);
    vector<int> values(k + 1, 0);
    
    for(int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    values[0] = 1;

    for(int i = 0; i < n; i++) {
        for(int j = 1; j <= k; j++) {
            if(j >= coins[i]) {
                values[j] += values[j - coins[i]];
            }
        }
    }

    cout << values[k];
    return 0;
}