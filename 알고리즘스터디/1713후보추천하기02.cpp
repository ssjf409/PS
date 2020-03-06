#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, recom;
    cin >> N >> recom;

    deque<pair<int, int>> dq;
    int cnt = 0;
    for(int i = 0; i < recom; i++) {

        int input_num;
        cin >> input_num;
        if(dq.empty()) {
            dq.push_back(make_pair(input_num, 1));
            cnt++;
            continue;
        }
        int min = 999999;
        int min_index = -1;
        bool search_flag = false;
        for(int i = 0; i < dq.size(); i++) {
            if(dq[i].second < min) {
                min = dq[i].second;
                min_index = i;
            }
            if(dq[i].first == input_num) {
                dq[i].second++;
                search_flag = true;
                break;
            }
        }
        if(!search_flag && cnt < N) {
            dq.push_back(make_pair(input_num, 1));
            cnt++;
        } else if(!search_flag) {
            
            dq[min_index].first = -1;
            dq[min_index].second = 999999;
            dq.push_back(make_pair(input_num, 1));
        }

    }

    vector<int> result;
    for(int i = 0; i < dq.size(); i++) {
        if(dq[i].first == -1) continue;
        result.push_back(dq[i].first);
        // cout << dq[i].first << ' ';
    }
    sort(result.begin(), result.end());

    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << ' ';
    }
    

    return 0;
}