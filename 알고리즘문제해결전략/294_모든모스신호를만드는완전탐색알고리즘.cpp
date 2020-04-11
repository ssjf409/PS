#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

// s : 지금까지 만든 신호
// n : 더 필요한 -의 개수
// m : 더 필요한 o의 개수
void generate(int n, int m, string s) {
    // 기저 사례 : n = m = 0
    if(n == 0 && m == 0) {
        cout << s << endl;
        return;
    }
    
    if(n > 0) generate(n - 1, m, s + "-");
    if(m > 0) generate(n, m - 1, s + "o");
}















int main() {
    return 0;
}