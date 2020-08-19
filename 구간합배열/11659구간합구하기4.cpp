#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<int> psum(N + 1, 0);

    int temp;
    int sum = 0;
    for(int i = 1; i <= N; i++) {
        cin >> temp;
        sum += temp;
        psum[i] = sum;
    }

    int a, b;
    for(int i = 0; i < M; i++) {
        cin >> a >> b;
        cout << psum[b] - psum[a - 1] << '\n';
    }

    return 0;
}