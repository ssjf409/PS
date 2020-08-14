#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T, n;

vector<vector<int>> cache;

vector<vector<int>> sticker;

int getMaxScore(int index, int preState) {
    if(index == n) return 0;

    int& ret = cache[index][preState];
    if(ret != -1) return ret;

    ret = 0;

    for(int i = 0; i < 3; i++) {
        if(preState != 2 && preState == i) continue;

        if(i == 2) {
            ret = max(ret, getMaxScore(index + 1, i));
        } else {
            ret = max(ret, getMaxScore(index + 1, i) + sticker[index][i]);
        }

    }

    return ret;
}


int main() {
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    while(T--) {
        cin >> n;
        cache.assign(n, vector<int>(3, -1));
        sticker.assign(n, vector<int>(3, 0));
        for(int j = 0; j < 2; j++) {
            for(int i = 0; i < n; i++) {
                cin >> sticker[i][j];
            }
        }
        cout << getMaxScore(0, 2) << '\n';
    }

    return 0;
}