#include <iostream>
#include <vector>
#define MAX 1000

using namespace std;

vector<int> triNum(MAX + 1);

inline bool findCase(int K) {
    for(int i = 1; i < K / 3 + 1; i++) {
        for(int j = i; j < K / 2 + 1; j++) {
            for(int s = j; s < K; s++) {
                if(triNum[i] + triNum[j] + triNum[s] == K) return true;
            }
        }
    }
    return false;
}

int main() {

    for(int i = 1; i <= MAX; i++) {
        triNum[i] = i * (i + 1) / 2;
    }

    int T;
    cin >> T;
    while(T--) {
        int K;
        cin >> K;
        if(findCase(K)) cout << "1\n";
        else cout << "0\n";
    }

    return 0;
}