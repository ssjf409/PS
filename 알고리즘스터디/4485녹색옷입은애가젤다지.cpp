// 실패!
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

#define INF 1e9

using namespace std;


void dijkstra(int a, int b, vector<vector<int>> &input_v, vector<vector<int>> &result_v) {
    int border = input_v[0].size() - 1;

    result_v[a][b] = input_v[a][b];
    priority_queue<tuple<int, int, int>> pq;
    pq.push(make_tuple(a, b, -input_v[a][b]));

    while(!pq.empty()) {
        pair<int, int> point;
        point.first = get<0>(pq.top());
        point.second = get<1>(pq.top());
        int distance = -get<2>(pq.top());
        pq.pop();

        if(result_v[point.first][point.second] < distance) {
            continue;
        }
        
        if(0 <= point.first - 1) {
            int next_x = point.first - 1;
            int next_y = point.second;
            int nextDistance = distance + input_v[next_x][next_y];
            if(nextDistance < result_v[next_x][next_y]) {
                result_v[next_x][next_y] = nextDistance;
                pq.push(make_tuple(next_x, next_y, -nextDistance));
            }
        }

        if(border >= point.second - 1) {
            int next_x = point.first;
            int next_y = point.second - 1;
            int nextDistance = distance + input_v[next_x][next_y];
            if(nextDistance < result_v[next_x][next_y]) {
                result_v[next_x][next_y] = nextDistance;
                pq.push(make_tuple(next_x, next_y, -nextDistance));
            }
        }

        if(border >= point.first + 1) {
            int next_x = point.first + 1;
            int next_y = point.second;
            int nextDistance = distance + input_v[next_x][next_y];
            if(nextDistance < result_v[next_x][next_y]) {
                result_v[next_x][next_y] = nextDistance;
                pq.push(make_tuple(next_x, next_y, -nextDistance));
            }
        }

        if(border >= point.second + 1) {
            int next_x = point.first;
            int next_y = point.second + 1;
            int nextDistance = distance + input_v[next_x][next_y];
            if(nextDistance < result_v[next_x][next_y]) {
                result_v[next_x][next_y] = nextDistance;
                pq.push(make_tuple(next_x, next_y, -nextDistance));
            }
        }
    }
}


int main() {
    int N;
    int cnt = 0;
    while(true) {
        cin >> N;

        vector<vector<int>> input_v(N, vector<int> (N));
        vector<vector<int>> result_v(N, vector<int> (N, INF));

        if(N == 0) {
            break;
        }
        for(int i = 0; i < N; i++) {
            int input_value;
            for(int j = 0; j < N; j++) {
                cin >> input_value;
                input_v[i][j] = input_value;
            }
        }

        
        dijkstra(0, 0, input_v, result_v);
        
        // for(int i = 0; i < N; i++) {
        //     for(int j = 0; j < N; j++) {
        //         cout << result_v[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
        cout << "Problem " << ++cnt << ": " << result_v[N-1][N-1] << '\n';
    }
    return 0;
}