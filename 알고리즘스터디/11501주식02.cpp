#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    return a.first > b.first;
}

int main() {
    int T;
    cin >> T;
    for(int i = 0 ; i < T; i++) {
        int N;
        cin >> N;
        priority_queue<pair<int, int>> pq;

        long long sum = 0;
        int max_val = 0;
        int max_index = 0;

        for(int i = 0; i < N; i++) {
            int temp;
            cin >> temp;
            pq.push(make_pair(temp, i));
        }

        while(!pq.empty()) {
            if(pq.top().second > max_index) {
                
            }
        }



    }
    return 0;
}