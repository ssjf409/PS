#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;

    int alphaCnt = 0;
    int arr[26] = {0,};

    string str;
    cin >> str;

    int index = 0;
    int maxLen = 0;
    for(int i = 0; i < str.size(); i++) {
        int cur = str[i] - 'a';
        if(arr[cur] > 0) {
            arr[cur]++;
        } else {
            if(alphaCnt < N) {
                arr[cur]++;
                alphaCnt++;
            } else {
                while(alphaCnt == N) {
                    int prev = str[index] - 'a';
                    arr[prev]--;
                    index++;
                    if(arr[prev] == 0) {
                        alphaCnt--;
                    }
                }
                arr[cur]++;
                alphaCnt++;
            }
        }
        if(maxLen < i - index + 1) {
            maxLen = i -index + 1;
        }
    }
    cout << maxLen;

    return 0;
}