#include <iostream>
#include <vector>

using namespace std;

int M, N;
vector<vector<int>> map_v;
vector<vector<bool>> visit;

void dfs(int a, int b) {
    if(visit[a][b]) return;
    visit[a][b] = true;

    if(a > 0) {
        dfs(a - 1, b);
    }
    if(a < M - 1) {
        dfs(a + 1, b);
    }
    if(b > 0 ) {
        dfs(a, b - 1);
    }
    if(b < N - 1) {
        dfs(a, b + 1);
    }
}

int main() {
    cin >> M >> N;
    for(int i = 0; i < M; i++) {
        string str;
        cin >> str;
        vector<int> temp;
        vector<bool> temp2;
        for(int j = 0; j < N; j++) {
            temp.push_back(str[j] - '0');
            if(str[j] == '0') {
                temp2.push_back(false);
            } else {
                temp2.push_back(true);
            }
        }
        map_v.push_back(temp);
        visit.push_back(temp2);
    }

    for(int i = 0; i < N; i++) {
        dfs(0, i);
    }

    int flag = false;
    for(int i = 0; i < N; i++) {
        if(!map_v[M-1][i] && visit[M-1][i]) {
            flag = true;
            break;
        }
    }


    // for(int i = 0; i < M; i++) {
    //     for(int j = 0; j < N; j++) {
    //         cout << map_v[i][j];
    //     }
    //     cout << '\n';
    // }

    // cout<< "\n==================\n";
    
    // for(int i = 0; i < M; i++) {
    //     for(int j = 0; j < N; j++) {
    //         cout << visit[i][j];
    //     }
    //     cout << '\n';
    // }


    if(flag) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}