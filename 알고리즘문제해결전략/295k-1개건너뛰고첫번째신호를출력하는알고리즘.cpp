#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int skip;

void generate2(int n, int m, string s) {
    // 기저 사례 : skip < 0
    if(skip < 0) return;
    // 기저 사례 : n = m = 0
    if(n == 0 && m == 0) {
        // 더 건너뛸 신호가 없는 경우
        if(skip == 0) cout << s << endl;
        --skip;
        return;
    }

    if(n > 0) generate2(n - 1, m, s + "-");
    if(m > 0) generate2(n, m - 1, s + "o");
}














int main() {
    return 0;
}