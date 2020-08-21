#include <iostream>
#include <vector>
#include <queue>
#define MAX 100000

using namespace std;

bool visited[MAX + 1];

int main() {
    int K, N;
    cin >> K >> N;

    priority_queue<int> pq;

    vector<int> value;

    int input;
    for(int i = 0; i < K; i++) {
        cin >> input;
        pq.push(-input);
    }

    int cnt = 0;
    int minValue;

    while(true) {
        minValue = -pq.top();
        pq.pop();
        value.push_back(minValue);
        if(++cnt == N) break;


        for(int i = 0; i < value.size(); i++) {
            if(value[i] * minValue > MAX || visited[value[i] * minValue]) break;
            visited[value[i] * minValue] = true;
            pq.push(-value[i] * minValue);
        }
    }


    cout << minValue;
    
    return 0;
}