#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#define MAX 100000

using namespace std;

int N;
vector<pair<int, int>> conf;
vector<int> idx1;

int cache[MAX + 2];

int getMax(int start) {

    int& ret = cache[start + 1];
    if(ret != -1) return ret;

    ret = 0;

    
    for(int i = lower_bound(idx1.begin(), idx1.end(), start) - idx1.begin() + 1; i < N; i++) {
        if(start == -1 || conf[start].second < conf[i].first) {
            ret = max(ret, getMax(i) + 1);
        }
    }

    return ret;
}



bool compare(const pair<int, int>& a, const pair<int, int>& b) {
    if(a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}

int main() {
    cin >> N;

    conf.assign(N, pair<int, int>());
    idx1.assign(N, 0);
    for(int i = 0; i < N; i++) {
        cin >> conf[i].first >> conf[i].second;
        idx1[i] = conf[i].first;
    }

    sort(conf.begin(), conf.end(), compare);

    // for(const auto& ele : conf) {
    //     cout << ele.first << ' ' << ele.second << '\n';
    // }

    memset(cache, -1, sizeof(cache));

    cout << getMax(-1);
    return 0;
}