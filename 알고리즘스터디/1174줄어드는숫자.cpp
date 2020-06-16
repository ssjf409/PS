#include <iostream>
#include <vector>
#include <cstring>

using namespace std;


int cache[11][11];
vector<int> v;


void getNum(int num, int x) {
    if(x == 1) return;
    if(num == 0) return;

    int ret = num;

    int nx;
    bool flag = true;
    for(int i = 0; i <= 9; i++) {
        if(num - cache[x][i] <= 0) {
            nx = i;
            flag = false;
            break;
        } else {
            num -= cache[x][i];
        }
    }
    v.push_back(nx);
}

int main() {
    int N;
    cin >> N;

    if(N > 1023) {
        cout << -1;
        return 0;
    }

    memset(cache, 0, sizeof(cache));

    for(int i = 0; i < 10; i++) {
        cache[1][i] = 1;
    }

    for(int i = 2; i <= 10; i++) {
        for(int j = 1; j <= 9; j++) {
            for(int k = 0; k < j; k++) {
                cache[i][j] += cache[i - 1][k];
            }
        }
    }

    // for(int i = 1; i <= 10; i++) {
    //     for(int j = 0; j <= 9; j++) {
    //         cout << cache[i][j] << ' ';
    //     }
    //     cout << endl;
    // }


    int cnt = N;
    long long ret = 0;
    while(cnt > 0) {
        ret *= 10;
        bool flag = false;
        int idx = 0;
        for(int i = 1; i <= 10; i++) {
            for(int j = i - 1; j <= 9; j++) {
                if(cnt - cache[i][j] <= 0) {
                    idx = i;
                    ret += j;
                    flag = true;
                    break;
                } else {
                    cnt -= cache[i][j];
                }
            }
            if(flag) break;
        }
        while(idx-- != 1) {
            ret *= 10;
            for(int j = idx - 1; j <= 9; j++) {
                if(cnt - cache[idx][j] <= 0) {
                    ret += j;
                    break;
                } else {
                    cnt -= cache[idx][j];
                }
            }
        }
        if(idx <= 1) break;
    }
    cout << ret;


    return 0;
}