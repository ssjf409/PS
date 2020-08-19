#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int K, N;
    cin >> K >> N;

    queue<int> q;
    vector<int> result;

    for(int i = 1; i <= K; i++) {
        q.push(i);
    }
    
    
    int temp = 0;
    while(!q.empty()) {
        if(++temp == N) {
            result.push_back(q.front());
            q.pop();
            temp = 0;
        } else {
            q.push(q.front());
            q.pop();
        }
    }

    cout << '<';

    for(int i = 0; i < result.size() - 1; i++) {
        cout << result[i] << ", ";
    }
    cout << result.back();
    cout << '>';

    return 0;
}