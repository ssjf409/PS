#include <iostream>

#define MAX 300

using namespace std;

int cache[MAX + 1];


int main() {
    int N;
    cin >> N;
    int stairValue[N + 1] = {0,};

    for(int i = 1; i <= N; i++) {
        cin >> stairValue[i];
    }

    cache[1] = stairValue[1];
    if(N == 1) {
        cout << cache[1]; 
        return 0;
    }
    cache[2] = max(cache[1] + stairValue[2], stairValue[2]);
    if(N == 2) {
        cout << cache[2]; 
        return 0;
    }
    cache[3] = max(cache[1] + stairValue[3], stairValue[2] + stairValue[3]);
    if(N == 3) {
        cout << cache[3]; 
        return 0;
    }

    for(int i = 4; i <= N; i++) {
        cache[i] = max(cache[i - 3] + stairValue[i - 1], cache[i - 2]) + stairValue[i];
    }

    cout << cache[N];
    return 0;
}