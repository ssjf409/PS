#include <iostream>
#include <vector>

using namespace std;



int main() {
    int N, M, K;

    cin >> N >> M;
    vector<vector<int>> input_v1(N, vector<int>(M));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> input_v1[i][j];
        }
    }
    
    cin >> M >> K;
    vector<vector<int>> input_v2(M, vector<int>(K));
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < K; j++) {
            cin >> input_v2[i][j];
        }
    }

    vector<vector<int>> result_v(N, vector<int>(K));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < K; j++) {
            int sum = 0;
            for(int k = 0; k < M; k++) {
                sum += input_v1[i][k] * input_v2[k][j];
            }
            cout << sum << ' ';
        }
        cout << '\n';
    }
    return 0;
}