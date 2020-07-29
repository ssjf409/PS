#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;


int main() {
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    int N;
    cin >> N;
    // start, end
    vector<pair<int, int>> lecture(N, pair<int, int>());

    priority_queue<int> pq;

    for(int i = 0; i < N; i++) {
        cin >> lecture[i].first >> lecture[i].second;
    }

    sort(lecture.begin(), lecture.end());

    pq.push(-lecture[0].second);

    for(int i = 1; i < N; i++) {
        int cstart = lecture[i].first;
        int cend = lecture[i].second;
        if(-pq.top() <= cstart) {
            pq.pop();
            pq.push(-cend);
        } else {
            pq.push(-cend);
        }
    }

    cout << pq.size();


    return 0;
}