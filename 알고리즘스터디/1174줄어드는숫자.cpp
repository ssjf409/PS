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
    getNum(num + cache[][nx], )

}

int main() {
    int N;
    cin >> N;

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


    // int before = 0;
    // int sum = 0;
    // for(int i = 1; i <= 10; i++) {
    //     before = sum;
    //     sum = 0;
    //     for(int j = 0; j <= 9; j++) {
    //         sum += cache[i][j];
    //         cache[i][j] += before;
    //     }
    //     cout << endl;
    // }



    for(int i = 1; i <= 10; i++) {
        for(int j = 0; j <= 9; j++) {
            cout << cache[i][j] << ' ';
        }
        cout << endl;
    }

    int y = 0;
    int x = 0;
    bool flag = true;
    int num = 0;
    for(int i = 1; i <= 10; i++) {
        for(int j = 0; j <= 9; j++) {
            if(N - cache[i][j] <= 0) {
                y = i;
                x = j;
                flag = false;
                break;
            } else {
                N -= cache[i][j];
            }
        }
        if(!false) break;
    }
    // int sum = 0;
    // for(int i = 1; i <= 10; i++) {
    //     for(int j = i - 1; j <= 9; j++) {
    //         sum += cache[i][j];
    //         cache[i][j] = sum;
    //     }
    //     cout << endl;
    // }


    // for(int i = 1; i <= 10; i++) {
    //     for(int j = 0; j <= 9; j++) {
    //         cout << cache[i][j] << ' ';
    //     }
    //     cout << endl;
    // }




    return 0;
}