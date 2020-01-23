#include <iostream>
#include <vector>
#include <string>

using namespace std;


void dfs(int a, int b, vector<vector<bool>> &layer_v, vector<vector<bool>> &result_v) {
    if()
}


int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> map_v(N+2, vector<int>(M+2, -1));

    for(int i = 1; i <= N; i++) {
        string str;
        cin >> str;
        for(int j = 1; j <= M; j++) {
            map_v[i][j] = str[j-1];
        }
    }
    for(int i = 2; i <= 9; i++) {
        vector<vector<bool>> layer_v(N+2, vector<bool>(M+2, false));
        for(int j = 1; j <= 9; j++) {
            for(int k = 1; k <= 9; k++) {
                if(map_v[j][k] >= i) {
                    layer_v[j][k] = true;
                }
            }
        }
        vector<vector<bool>> result_v(N+2, vector<bool>(M+2, false));
        for(int j = 1; j <= 9; j++) {
            for(int k = 1; k <= 9; k++) {
                dfs(j,k,layer_v,result_v);
            }
        }
    }
    return 0;
}