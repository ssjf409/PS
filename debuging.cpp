#include <iostream>
#include <vector>
#define INF 987654321 

using namespace std;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, 1, -1};
void isClose(vector<vector<int>>& circle, int y, int x) {
    int dot = circle[y][x];
    if(y + dy[0] >= 0) {
        if(circle[y + dy[0]][x] == dot) circle[y + dy[0]][x] = INF;
    }
    if(y + dy[1] < circle.size()) {
        if(circle[y + dy[1]][x] == dot) circle[y + dy[1]][x] = INF;
    }
    if(x + dx[3] < circle[0].size()) {
        if(circle[y][x + dx[3]] == dot) circle[y][x + dx[3]] = INF;
    }
    if(x + dx[4] >= 0) {
        if(circle[y][x + dx[4]] == dot) circle[y][x + dx[4]] = INF;
    }
}

void deleteClose(vector<vector<int>>& circle, int y, int x) {
    if(y + dy[0] >= 0) {
        circle[y + dy[0]][x] = 0;
    }
    if(y + dy[1] < circle.size()) {
        circle[y + dy[1]][x] = 0;
    }
    if(x + dx[3] < circle[0].size()) {
        circle[y][x + dx[3]] = 0;
    }
    if(x + dx[4] >= 0) {
        circle[y][x + dx[4]] = 0;
    }
}

int main() {
    int N, M, T;
    cin >> N >> M >> T;
    vector<vector<int>> circle;
    for(int i = 0; i < N; i++) {
        vector<int> temp;
        int t;
        for(int j = 0; j < M; j++) {
            cin >> t;
            temp.push_back(t);
        }
        circle.push_back(temp);
    }

    int x, d, k;
    for(int i = 0; i < T; i++) {
        cin >> x >> d >> k;
        int arr[N+1] = {0};
        for(int j = 0; j < N; j++) {
            if((j+1) % x == 0 && d == 0) {
                arr[j] += k;
            } else if( (j+1) % x == 0 && d == 1) {
                arr[j] -= k;
            }
        }
        int temp[M] = {0};
        for(int j = 0; j < N; j++) {
            for(int l = 0; l < M; l++) {
                temp[(l + temp[l]) % M] = circle[j][l];
            }
            for(int l = 0; l < M; l++) {
                circle[j][l] = temp[l];
            }
        }
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            isClose(circle, i, j);
        }
    }
    double sum = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(circle[i][j] != INF) sum += circle[i][j];
        }
    }
    sum +=
    



    return 0;
}