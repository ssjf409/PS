#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const pair<int, int>& a, const pair<int, int>& b) {
    if(a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int main() {
    int N;
    cin >> N;
    vector<pair<int, int>> meeting(N, pair<int, int>());

    for(int i = 0; i < N; i++) {
        cin >> meeting[i].first >> meeting[i].second;
    }

    sort(meeting.begin(), meeting.end(), compare);

    int startTime = 0;
    int cnt = 0;
    for(int i = 0; i < N; i++) {
        if(meeting[i].first < startTime) continue;
        startTime = meeting[i].second;
        cnt++;
    }
    cout << cnt;

    return 0;
}