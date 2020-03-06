#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<pair<int, int>> input_v;
int K;

bool compare(pair<int, int> a, pair<int, int> b) {
    if(a.first == b.first) {
        return a.second > b.second;
    }
    return a.first < b.first;
}


int getValue(int index, int cur_k, int tot_value) {
    for(int i = index + 1; i < input_v.size(); i++) {
        if(input_v[i].first + cur_k > K) {
            return tot_value;
        }
        return getValue(i, input_v[i].first + cur_k, tot_value + input_v[i].second);
    }
    return tot_value;
}

int main() {
    int N, W, V;
    cin >> N >> K;


    for(int i = 0; i < N; i++) {
        cin >> W >> V;
        input_v.push_back(make_pair(W, V));
    }

    sort(input_v.begin(), input_v.end(), compare);

    int max_result = 0;
    for(int i = 0; i < N; i++) {
        int result;
        if(K >= input_v[i].first) {
            result = getValue(i, input_v[i].first, input_v[i].second);    
        }
        if(result > max_result) {
            max_result = result;
        }
    }
    

    cout << max_result;

    return 0;
}