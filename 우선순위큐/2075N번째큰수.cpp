#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;

    priority_queue<int> pq;

    int input;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> input;
            if(!pq.empty() && input < -pq.top()) continue;
            pq.push(-input);
            if(pq.size() == N + 1) {
                pq.pop();
            }
        }
    }

    cout << -pq.top();

    return 0;
}