#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    if(a.first == b.first) {
        return a.second < b.second;
    }
    return a.first < b.first;
}

int main() {
    int N;
    cin >> N;

    int n = N - 1;
    vector<pair<int, int>> v_input(n);
    for(int i = 0; i < n; i++) {
        cin >> v_input[i].first >> v_input[i].second;
    }

    sort(v_input.begin(), v_input.end(), compare);

    queue<int> q;

    int first = 1;
    bool odd_flag = false;
    int odd_cnt = 0;
    int even_cnt = 0;
    bool check[v_input.size()] = {false};

    q.push(first);
    while(!q.empty()) {
        int length = q.size();

        if(odd_flag) {
            odd_flag = false;
            even_cnt += length;
        } else {
            odd_flag = true;
            odd_cnt += length;
        }
        
        for(int i = 0; i < length; i++) {
            int target = q.front();
            q.pop();
            for(int j = 0; j < v_input.size(); j++) {
                if(check[j]) {
                    continue;
                }
                if(v_input[j].first == target){
                    q.push(v_input[j].second);
                    check[j] = true;
                } else if(v_input[j].second == target){
                    q.push(v_input[j].first);
                    check[j] = true;
                }
            }

        }
    }

    odd_cnt > even_cnt ? cout << even_cnt : cout << odd_cnt;
    return 0;
}