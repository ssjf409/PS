#include <iostream>
#include <vector>

using namespace std;

int T, N, M;

int main() {
    cin >> T;
    for(int testCase = 0; testCase < T; testCase++) {
        cin >> N >> M;
        cout << N - 1 << '\n';
        int a, b;
        for(int i = 0; i < M; i++) {
            cin >> a >> b;
        }
    }

    return 0;
}