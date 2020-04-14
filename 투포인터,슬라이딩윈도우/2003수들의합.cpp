#include <iostream>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    int arr[N];
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    int cnt = 0, sum = 0, lo = 0, hi = 0;

    while(1) {
        if(sum >= M) sum -= arr[lo++];
        else if(hi == N) break;
        else sum += arr[hi++];

        if(sum == M) cnt++;
    }

    cout << cnt;

    return 0;
}