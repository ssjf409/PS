#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    priority_queue<int> pq;
    int input;
    for(int i = 0; i < 15; i++) {
        cin >> input;
        pq.push(-input);
    }

    while(pq.size() != 1) {
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();
        pq.push(first + second);
    }

    cout << -pq.top();


    return 0;
}