#include <iostream>
#include <vector>
#include <cstring>

using namespace std;


// 전부 -1로 초기화해 둔다.
int cache[2500][2500];
// a와 b는 각각 [0, 2500) 구간 안의 정수.
int someObscureFunction(int a, int b) {
    // 기저 사례를 처음에 처리한다.
    if(a == b) return 1;
    // (a, b)에 대한 답을 구한 적이 있으면 곧장 반환
    int& ret = cache[a][b];
    if(ret != -1) return ret;
    // 여기에서 답을 계산한다.
    // ...
    return ret;
}

int main() {
    // memset()을 이용해 cache 배열을 초기화한다.
    memset(cache, -1, sizeof(cache));

    // for(auto i = 0; i < 10; i++) {
    //     for(auto j = 0; j < 10; j++) {
    //         cout << cache[i][j];
    //     }
    //     cout << '\n';
    // }
}