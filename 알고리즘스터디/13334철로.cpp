#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// bool compare(pair<int, int> a, pair<int, int> b){
//     return a.first < b.first;
// }

int main() {
    int N, input_a, input_b;
    int d;
    int max_cnt = 0;
    cin >> N;
    
    vector<pair<int, int>> input_v(N);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for(int i = 0; i < N; i++) {
        cin >> input_a >> input_b;
        // if(input_a < input_b) {
        //     input_v[i].first = input_a;
        //     input_v[i].second = input_b;
        // } else {
        //     input_v[i].first = input_b;
        //     input_v[i].second = input_a;
        // }
        pq.push(make_pair(input_a, input_b));
    }
    int k = 0;
    while(!pq.empty()) {
        input_v[k].first = pq.top().first;
        input_v[k].second = pq.top().second;
        // cout << input_v[k].first << ' ' << input_v[k].second << '\n';
        pq.pop();
        k++;
    }

    cin >> d;

    // sort(input_v.begin(), input_v.end(), compare);

    
    // for(int i = 0; i < N; i++) {
    //     cout << input_v[i].first << ' ' << input_v[i].second << '\n';
    // }


    for(int i = 0; i < input_v.size(); i++) {
        int cnt = 0;
        int j = i;
        int start = input_v[i].first;
        int end = (input_v[i].first + d) > input_v[N-1].second ? input_v[N-1].second : (input_v[i].first + d);
        while(input_v[j].first <= end && j < N) {
            if(input_v[j].second >= start && input_v[j].second <= end) {
                cnt++;
            }
            j++;
        }
        if(cnt > max_cnt) {
            max_cnt = cnt;
        }
    }

    cout << max_cnt;


    return 0;
}