#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
#define START 100

using namespace std;


int main() {
    int N, M;
    cin >> N >> M;

    vector<bool> isDisable(10, false);

    int a;
    for(int i = 0; i < M; i++) {
        cin >> a;
        isDisable[a] = true;
    }


    int minVal = 1000000;
    for(int i = 0; i <= 1000000; i++) {
        int term = abs(N - START);

        bool canMake = true;
        string str = to_string(i);

        for(int j = 0; j < str.size(); j++) {
            if(isDisable[str[j] - '0']) {
                canMake = false;
                break;
            }
        }

        if(canMake) {
            term = min(term, (int)str.size() + abs(N - i));
        }

        if(term < minVal) {
            minVal = term;
        }

    }

    cout << minVal;

    return 0;
}