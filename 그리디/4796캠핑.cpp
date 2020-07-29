#include <iostream>
#include <vector>

using namespace std;

int main() {
    int L, P, V;
    int caseNum = 1;
    while(true) {
        cin >> L >> P >> V;
        if(L == 0 && P == 0 && V == 0) break;

        int cnt = (V / P) * L;
        V %= P;
        cnt += (L < V) ? L : V;

        cout << "Case " << caseNum << ": " << cnt << '\n';

        caseNum++;
    }

    return 0;
}