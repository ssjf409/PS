#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    int N, M;

    cin >> N;
    vector<int> crane(N);
    for(int i = 0; i < N; i++) {
        cin >> crane[i];
    }

    cin >> M;
    multiset<int> s;
    int a;
    for(int i = 0; i < M; i++) {
        cin >> a;
        s.insert(a);
    }

    sort(crane.begin(), crane.end());

    if(crane.back() < *(--s.end())) {
        cout << -1;
        return 0;
    }

    int time = 0;

    // auto iter = s.lower_bound(6);

    while(!s.empty()) {
        time++;
        for(int i = N - 1; i >= 0; i--) {
            if(s.empty()) break;

            auto iter = s.lower_bound(crane[i]);
            if(s.begin() == iter) {
                time++;
                break;
            }
            s.erase(iter);

        }
    }

    cout << time;


    return 0;
}