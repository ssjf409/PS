#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;


int main() {
    int N, input_a, input_b;
    int d;
    int max_cnt = 0;
    cin >> N;
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for(int i = 0; i < N; i++) {
        cin >> input_a >> input_b;
        if(input_a < input_b) {
            pq.push(make_pair(input_a, input_b));
        } else {
            pq.push(make_pair(input_b, input_a));
        }
        
    }
    


    cin >> d;


    // while(!pq.empty()) {
    //     cout << pq.top().first << ' ' << pq.top().second << '\n';
    //     pq.pop();
    // }
    int pq_length = pq.size();
    for(int i = 0; i < pq_length; i++) {
        int start = pq.top().first;
        for(int j = i; j < pq_length; j++) {
            
        }
    }


    // int start = pq.top().first;
    // int end = start + d;
    // int cnt = 0;
    // while(!pq.empty()) {
        
    //     if(pq.top().second > end) {
            
    //         start = pq.top().first;
    //         end = start + d;
    //         if(cnt > max_cnt) {
    //             max_cnt = cnt;
    //         }
    //         cnt = 0;

    //         pq.pop();
    //         continue;
    //     }

    //     cnt++;
    //     pq.pop();


    // }

    cout << max_cnt;


    return 0;
}