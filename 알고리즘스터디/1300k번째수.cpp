#include <iostream>
#include <queue>

using namespace std;

int main() {
    int N, k;
    cin >> N;
    cin >> k;

    priority_queue<int> pq;

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            pq.push(-1*i*j);
        }
    }

    
    for(int i = 1; i < k; i++) {
        pq.pop();
    }
    cout << -1 * pq.top();


    return 0;
}