#include <iostream>
#include <vector>
#include <algorithm>
#define PROB_NUM 11

using namespace std;

int main() {
    vector<pair<int, int>> problems(PROB_NUM);

    for(int i = 0; i < PROB_NUM; i++) {
        cin >> problems[i].first >> problems[i].second;
    }

    sort(problems.begin(), problems.end());

    int penalty = 0;
    int time = 0;
    for(int i = 0; i < PROB_NUM; i++) {
        time += problems[i].first;
        penalty += (time + 20 * problems[i].second);
    }
    
    cout << penalty;

    return 0;
}