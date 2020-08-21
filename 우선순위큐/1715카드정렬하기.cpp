#include <iostream>
#include <queue>

using namespace std;

int main() {
    int N;
    cin >> N;

    int num = 0;
    priority_queue<int> pq;

    int input;
    for(int i = 0; i < N; i++) {
        cin >> input;
        pq.push(-input);
    }

    while(pq.size() != 1) {
        int temp = -pq.top();
        pq.pop();
        int temp2 = -pq.top();
        pq.pop();
        num += temp + temp2;
        pq.push(-(temp + temp2));
    }

    cout << num;

    return 0;
}