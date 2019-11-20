#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, k;
    cin >> N >> k;
    int cnt = 0;

    vector<int> v(N);
    
    for(int i = 0; i < N; i++) {
        cin >> v[i];
    }

    for(int i = N - 1; i >= 0; i--) {
        int tmp = k / v[i];
        if(tmp) {
            k -= tmp * v[i];
            cnt += tmp;
        }
    }

    cout << cnt;
    return 0;
}