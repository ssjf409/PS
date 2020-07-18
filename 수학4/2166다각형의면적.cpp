#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<pair<int, int>> point(N, pair<int, int>());

    for(int i = 0; i < N; i++) {
        cin >> point[i].first >> point[i].second;
    }




    return 0;
}