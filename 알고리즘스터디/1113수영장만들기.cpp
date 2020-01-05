#include <iostream>
#include <vector>
#include <string>

using namespace std;


vector<vector<pair<int, bool>>> v;

int sum = 0;
int height = 0;


void dfs(int a, int b) {
    if(v[a][b].second) return;
    v[a][b].second = true;
    
}

int main() {
    // N, M이 3보다 작으면 무조건 0 리턴
    int N, M;
    cin >> N >> M;

    
    for(int i = 0; i < N; i++) {
        vector<pair<int, bool>> v_row(M, make_pair(0, false));
        v.push_back(v_row);
    }

    for(int i = 0; i < N; i++) {
        string str;
        cin >> str;
        for(int j = 0; j < M; j++) {
            v[i][j].first = str[j];
        }
    }

    for(height = 9; height > 0; height--) {
        for(int i = 1; i < N - 1; i++) {
            for(int j = 1; j < M - 1; j++) {
                dfs(i, j);
            }
        }
    }



    return 0;
}