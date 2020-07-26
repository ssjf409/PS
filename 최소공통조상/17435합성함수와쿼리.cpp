#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> board;
int N;

int main() {
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    board.assign(19, vector<int>(N + 1, 0));
    
    for(int i = 1; i <= N; i++){
        cin >> board[0][i];
    }

    for(int i = 1; i < 19; i++) {
        for(int j = 1; j <= N; j++) {
            board[i][j] = board[i - 1][board[i - 1][j]];
        }
    }

    int Q;
    cin >> Q;
    int n, x;
    for(int i = 0; i < Q; i++) {
        cin >> n >> x;
        for(int i = 18; i >= 0; i--) {
            if(n >= (1 << i)) {
                n -= (1 << i);
                x = board[i][x];
            }
        }
        cout << x << endl;
    }

    return 0;
}