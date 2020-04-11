#include <iostream>
#include <vector>
#include <cstring>
#define MAX_N 1000

using namespace std;

int n, m;
int cache[MAX_N][2 * MAX_N + 1];

// 달팽이가 days일 동안 climbed미터를 기어올라 왔다고 할 때,
// m일 전가지 n미터를 기어올라갈 수 있는 경우의 수
int climb(int days, int climbed) {
    // 기저 사례 : m일이 모두 지난 경우
    if(days == m) return climbed >= n ? 1 : 0;
    // 메모이제이션
    int& ret = cache[days][climbed];
    if(ret != -1) return ret;
    return ret = climb(days + 1, climbed + 1) + climb(days + 1, climbed + 2);
}












int main() {
    return 0;
}