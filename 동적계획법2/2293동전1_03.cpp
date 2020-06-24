#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;
int n, k;

vector<int> coins;
vector<int> values;

void getValueCnt(int index) {
    if(index == n) return;

    for(int i = 1; i <= k; i++) {
        if(i - coins[index] >= 0) {
            values[i] += values[i - coins[index]];
        }
    }

    getValueCnt(index + 1);
}


int main() {
    cin >> n >> k;

    coins.assign(n, 0);
    values.assign(k + 1, 0);

    
    for(int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    values[0] = 1;

    getValueCnt(0);

    cout << values[k];
    return 0;
}