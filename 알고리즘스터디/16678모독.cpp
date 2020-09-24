#include <iostream>
#include <queue>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    priority_queue<int> pq;

    int a;
    while(N--) {
        cin >> a;
        pq.push(-a);
    }

    int num = 1;
    long long cnt = 0;
    while(!pq.empty()) {
        int top = -pq.top();
        pq.pop();
        if(top >= num) {
            cnt += top - num;
        } else {
            continue;
        }

        num++;
    }

    cout << cnt;


    return 0;
}