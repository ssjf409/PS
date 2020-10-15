#include <iostream>
#include <vector>

using namespace std;

vector<vector<vector<int>>> tetromino = {
    {
        {1, 1, 1, 1}
    },
    {
        {1},
        {1},
        {1},
        {1}
    },
    {
        {1, 1},
        {1, 1}
    },
    {
        {1, 1, 1},
        {1, 0, 0}
    },
    {
        {1, 1},
        {0, 1},
        {0, 1}
    },
    {
        {0, 0, 1},
        {1, 1, 1}
    },
    {
        {1, 0},
        {1, 0},
        {1, 1}
    },
    {
        {1, 1, 1},
        {0, 0, 1}
    },
    {
        {0, 1},
        {0, 1},
        {1, 1}
    },
    {
        {1, 0, 0},
        {1, 1, 1}
    },
    {
        {1, 1},
        {1, 0},
        {1, 0}
    },
    {
        {1, 0},
        {1, 1},
        {0, 1},
    },
    {
        {0, 1, 1},
        {1, 1, 0}
    },
    {
        {0, 1},
        {1, 1},
        {1, 0},
    },
    {
        {1, 1, 0},
        {0, 1, 1}
    },
    {
        {1, 1, 1},
        {0, 1, 0}
    },
    {
        {0, 1},
        {1, 1},
        {0, 1}
    },
    {
        {0, 1, 0},
        {1, 1, 1}
    },
    {
        {1, 0},
        {1, 1},
        {1, 0}
    }
};


int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> board(N, vector<int>(M));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }

    int max = 0;

    for(int k = 0; k < tetromino.size(); k++) {
        vector<vector<int>>& block = tetromino[k];
        int h = block.size();
        int w = block[0].size();
        for(int i = 0; i < N - h + 1; i++) {
            for(int j = 0; j < M - w + 1; j++) {
                int sum = 0;
                for(int s = 0; s < h; s++) {
                    for(int t = 0; t < w; t++) {
                        sum += board[i + s][j + t] * block[s][t];
                    }
                }
                if(sum > max) {
                    max = sum;
                }
            }
        }
    }

    cout << max;

    return 0;
}