#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> input_v;
queue<pair<int,int>> q;

int day_cnt = 0;
bool print_minor = false;

void diffusion(int a, int b) {
    if(input_v[a+1][b] == 0) {
        input_v[a+1][b] = 1;
        q.push(make_pair(a+1, b));
    }
    if(input_v[a-1][b] == 0) {
        input_v[a-1][b] = 1;
        q.push(make_pair(a-1, b));
    }
    if(input_v[a][b+1] == 0) {
        input_v[a][b+1] = 1;
        q.push(make_pair(a, b+1));
    }
    if(input_v[a][b-1] == 0) {
        input_v[a][b-1] = 1;
        q.push(make_pair(a, b-1));
    }
}


int main() {
    int M, N;
    cin >> M >> N;
    input_v.assign(N+2, vector<int>(M+2, -2));
    
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            int temp;
            cin >> temp;
            input_v[i][j] = temp;
            if(temp == 1) {
                q.push(make_pair(i, j));
            }
        }
    }

    while(!q.empty()) {
        day_cnt++;
        int q_length = q.size();
        for(int i = 0; i < q_length; i++) {
            diffusion(q.front().first, q.front().second);
            q.pop();
        }
        
        // for(int i = 0; i < N+2; i++) {
        //     for(int j = 0; j < M+2; j++) {
        //         cout << input_v[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
        // cout << '\n';
    }
    
    // for(int i = 0; i < N+2; i++) {
    //     for(int j = 0; j < M+2; j++) {
    //         cout << input_v[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            if(input_v[i][j] == 0) {
                cout << -1;
                return 0;
            }
        }
    }


    cout << --day_cnt;


    return 0;
}