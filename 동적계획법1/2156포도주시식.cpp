#include <iostream>
#include <vector>

using namespace std;



int main() {
    int n;
    cin >> n;

    int dp0[n] = {0,};
    int dp1[n] = {0,};
    int wine[n];
    int beforeMax;
    int Max = -1;
    int temp;

    for(int i = 0; i < n; i++) {
        cin >> wine[i];
    }

    dp0[0] = wine[0];
    dp0[1] = wine[1];
    dp1[0] = wine[0];
    dp1[1] = wine[0] + wine[1];
    beforeMax = wine[0];
    Max = max(dp0[1], dp1[1]);

    for(int i = 2; i < n; i++) {
        dp0[i] = beforeMax + wine[i];
        dp1[i] = dp0[i - 1] + wine[i];
        beforeMax = Max;
        Max = max(max(dp0[i], dp1[i]), Max);
    }

    cout << Max;
    
}