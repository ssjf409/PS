#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> time;
vector<int> money;
vector<bool> visited;

int maxMoney = 0;

void dfs(int index) {
    if(index >= N) {
        int sum = 0;
        for(int i = 0; i < N; i++) {
            if(visited[i] && N - i - time[i] >= 0) {
                sum += money[i];
            }
        }
        if(sum > maxMoney) {
            maxMoney = sum;
        }


        return;
    }

    dfs(index + 1);
    if(index + time[index] <= N) {
        visited[index] = true;
        dfs(index + time[index]);
        visited[index] = false;
    }
}

int main() {
    cin >> N;

    time.resize(N);
    money.resize(N);
    visited.assign(N, false);

    for(int i = 0; i < N; i++) {
        cin >> time[i] >> money[i];
    }


    dfs(0);

    cout << maxMoney;

    return 0;
}