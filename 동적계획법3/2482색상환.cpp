#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987654321

using namespace std;

int N, K;
// int arr[1001];
bool visited[1001];
int cache[1001][1001][2];

int getNumChoice(int index, int cnt) {
    if(cnt == 0) {
        if(visited[0] != visited[N - 1]) return 1;
        return 0;
    }

    int ret = 0;

    for(int next = index + 1; next < N; next++) {
        if(visited[index]) continue;
        visited[next] = true;
        ret += getNumChoice(next, cnt - 1);
        visited[next] = false;
    }

    return ret;
}

int main() {
    cin >> N >> K;

    
    cout << getNumChoice(-1, K);

    return 0;
}