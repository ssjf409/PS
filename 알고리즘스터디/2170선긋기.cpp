#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;
    vector<pair<int, int>> lines(N, pair<int, int>());
    for(int i = 0; i < N; i++) {
        cin >> lines[i].first >> lines[i].second;
    }

    sort(lines.begin(), lines.end());


    int end = lines[0].second;
    int len = lines[0].second - lines[0].first;
    for(int i = 1; i < N; i++) {
        int curStart = lines[i].first;
        int curEnd = lines[i].second;
        if(end >= curStart) {
            if(end >= curEnd) continue;
            len += curEnd - end;
        } else {
            len += curEnd - curStart;
        }
        end = (curEnd > end) ? curEnd : end;
    }

    cout << len;

    return 0;
}