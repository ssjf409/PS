#include <iostream>
#include <vector>

using namespace std;

int flag_true_cnt = 0;
int flag_false_cnt = 0;

vector<vector<int>> input_v;
vector<bool> visit;

void dfs(int a, bool flag) {
    if(visit[a]) return;
    visit[a] = true;
    flag ? flag_true_cnt++ : flag_false_cnt++;

    for(int i = 0; i < input_v[a].size(); i++) {
        int temp = input_v[a][i];
        flag ? dfs(temp, false) : dfs(temp, true);
    }
}

int main() {
    int N;
    cin >> N;
    for(int i = 0; i <= N; i++) {
        vector<int> temp;
        input_v.push_back(temp);
        visit.push_back(false);
    }
    
    for(int i = 1; i < N; i++) {
        int input_a, input_b;
        cin >> input_a >> input_b;
        input_v[input_a].push_back(input_b);
        input_v[input_b].push_back(input_a);
    }

    
    dfs(1, true);

    if(flag_true_cnt > flag_false_cnt) {
        cout << flag_false_cnt;
    } else {
        cout << flag_true_cnt;
    }
    return 0;
}