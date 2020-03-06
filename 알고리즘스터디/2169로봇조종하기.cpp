#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> map(N, vector<int>(M));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }

    vector<long long> rightside(M);
    vector<long long> leftside(M);
    vector<long long> temp(M);

    long long sum = 0;
    for(int i = 0; i < M; i++) {
        sum += map[0][i];
        temp[i] = sum;
    }

    for(int i = 1; i < N; i++) {

        rightside[0] = temp[0] + map[i][0];
        for(int j = 1; j < M; j++) {
            rightside[j] = max(temp[j], rightside[j - 1]) + map[i][j];
        }

        leftside[M - 1] = temp[M - 1] + map[i][M - 1];
        for(int j = M - 2; j >= 0; j--) {
            leftside[j] = max(temp[j], leftside[j + 1]) + map[i][j];
        }

        for(int j = 0; j < M; j++) {
            temp[j] = max(rightside[j], leftside[j]);
        }

    }
    
    cout << temp[M-1];

    return 0;
}