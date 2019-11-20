#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int N;
    int K;
    cin >> N;
    cin >> K;

    queue<int> q;
    vector<int> v;

    for(int i = 1; i <= N; i++) {
        q.push(i);
    }
    
    while(!q.empty()) {
        
        for(int i = 1; i < K; i++) {
            q.push(q.front());
            q.pop();
        }

        v.push_back(q.front());
        q.pop();
    }

    cout << '<' << v[0];
    for(int i = 1; i < v.size(); i++) {
        cout << ", " << v[i];
    }
    cout << '>';

    return 0;
}