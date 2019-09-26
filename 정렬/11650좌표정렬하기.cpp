#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    if(a.first == b.first) {
        return a.second < b.second;
    } else {
        return a.first < b.first;
    }
}

int main() {
    int N;
    int first;
    int second;

    cin >> N;
    vector<pair<int,int>> p;

    for(int i = 0; i < N; i++) {
        // cin >> first;
        // cin >> second;
        scanf("%d", &first);
        scanf("%d", &second);
        p.push_back(make_pair(first, second));
    }
    sort(p.begin(), p.end(), compare);

    for(int i = 0; i < p.size(); i++) {
        // cout << p[i].first << ' ' << p[i].second << endl;
        printf("%d %d\n", p[i].first, p[i].second);
    }

    return 0;
}