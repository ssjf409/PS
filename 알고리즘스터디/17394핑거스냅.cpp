#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <queue>

#define MAX_N 1000000

using namespace std;

int n;
bool isPrime[MAX_N + 1];
vector<bool> visited;


void eratosthenes() {
	memset(isPrime, 1, sizeof(isPrime));
	isPrime[0] = isPrime[1] = false;
	int sqrtn = int(sqrt(n));
	for(int i = 2; i <= sqrtn; i++) {
		if(isPrime[i]) {
			for(int j = i * i; j <= n; j += i) {
				isPrime[j] = false;
			}
		}
	}

}

int getNext(int cur, int dir) {
    switch(dir) {
        case 0:
            return cur / 2;
        break;
        case 1:
            return cur / 3;
        break;
        case 2:
            return cur + 1;
        break;
        case 3:
            return cur - 1;
        break;
    }
}


int dfs(int start, int left, int right) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    int cnt = 0;

    while(!q.empty()) {
        int qSize = q.size();
        for(int i = 0; i < qSize; i++) {
            int cur = q.front();
            q.pop();

            if(cur >= left && cur <= right && isPrime[cur]) return cnt;


            for(int j = 0; j < 4; j++) {
                int next = getNext(cur, j);
                if(next > right) continue;
                if(visited[next]) continue;
                if(j >= 2 && cur == 0) continue;
                visited[next] = true;
                q.push(next);

            }
            


        }
        cnt++;
    }
    return -1;
}

int main() {
    eratosthenes();
    
    int T, N, A, B;
    cin >> T;
    while(T--) {
        cin >> N >> A >> B;
        visited.assign(N + 1, false);

        cout << dfs(N, A, B) << "\n";

    }

    return 0;
}