#include <iostream>
#include <vector>
#define inf 987654321

using namespace std;

int n;
vector<vector<int>> board;

vector<vector<int>> floydwarshall() {
	vector<vector<int>> ret;

	ret = board;

	for(int k = 0; k < n; k++) {
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				if(ret[i][k] + ret[k][j] < ret[i][j]) {
					ret[i][j] = ret[i][k] + ret[k][j];
				}
			}
		}
	}
	return ret;
}


int main() {
	int m;
	cin >> n >> m;
	board.assign(n, vector<int>(n, inf));

	int u, v, cost;
	for(int i = 0; i < m; i++) {
		cin >> u >> v >> cost;
		if(board[u - 1][v - 1] > cost) {
			board[u - 1][v - 1] = cost;
		}
	}

	for(int i = 0; i < n; i++) {
		board[i][i] = 0;
	}

	vector<vector<int>> temp = floydwarshall();
	
	for(const auto& el : temp) {
		for(const auto& e : el) {
			if(e == inf) cout << 0 << ' ';
			else cout << e << ' ';
		}
		cout << '\n';
	}

	
    return 0;
}