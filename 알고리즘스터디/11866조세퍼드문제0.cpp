#include <iostream>
#include <queue>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    
    queue<int> q;
    for(int i = 1; i <= N; i++) {
        q.push(i);
    }

    int cnt = 0;
    cout << "<";

    while(q.size() != 1) {
        int temp = q.front();
        q.pop();
        if(++cnt % K == 0) {
            cout << temp << ", ";
            continue;
        }
        q.push(temp);
    }

    cout << q.front() << ">";

    return 0;
}