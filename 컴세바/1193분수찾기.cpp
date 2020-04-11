#include <iostream>

using namespace std;

int main() {
    int X;
    int sum = 0;
    cin >> X;
    int cnt = 1;
    int i, j;
    bool flag = false; // false일때는 ?,1 시작 true 일때는 1,?시작
    while(true) {
        if(X - cnt <= 0) break;
        X -= cnt;
        cnt++; 
        if(flag) flag = false;
        else flag = true;
    }

    if(flag) {
        i = X;
        j = cnt - X + 1;
    } else {
        i = cnt - X + 1;
        j = X;
    }
    cout << i << '/' << j;

}