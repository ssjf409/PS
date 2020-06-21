#include <iostream>
#include <vector>
#define INF 987654321

using namespace std;

int V, E;

vector<vector<int>> board;

vector<vector<int>> floydWarshall() {
    vector<vector<int>> ret;

    ret = board;

    for(int k = 0; k < V; k++) {
        for(int i = 0; i < V; i++) {
            for(int j = 0; j < V; j++) {
                if(ret[i][k] + ret[k][j] < ret[i][j]) {
                    ret[i][j] = ret[i][k] + ret[k][j];
                }
            }
        }
    }
    return ret;
}


int main() {
    cin >> V >> E;
    board.assign(V, vector<int>(V, INF));

    int u, v, cost;
    for(int i = 0; i < E; i++) {
        cin >> u >> v >> cost;
        if(board[u - 1][v - 1] > cost) {
            board[u - 1][v - 1] = cost;
        }
    }

    for(int i = 0; i < V; i++) {
        board[i][i] = 0;
    }


    vector<vector<int>> temp = floydWarshall();

    int min = INF;
    for(int i = 0; i < V; i++) {
        for(int j = 0; j < V; j++) {
            if(i == j) continue;
            if(temp[i][j] == INF || temp[j][i] == INF) continue;
            int cycle = temp[i][j] + temp[j][i];
            if(cycle < min) {
                min = cycle;
            }
        }
    }

    if(min == INF) {
        cout << -1;
    } else {
        cout << min;
    }



    return 0;
}