#include <iostream>
#include <cstring>
#define MAX 16
#define MAXBIT 1 << 16
#define INF 987654321

using namespace std;

int N;
int arr[MAX][MAX];
int cache[MAX][MAXBIT]; // 1111 1111 1111 1111 , 65535

int getMin(int here, int visit) {
    int& ret = cache[here][visit];
    if(ret != -1) return ret;
    
    if(visit == (1 << N) -1) {
        if(arr[here][0] == 0) return INF;
        return arr[here][0];
    }

    ret = INF;

    for(int next = 0; next < N; next++) {
        if(visit & (1 << next) || arr[here][next] == 0) continue;
        ret = min(ret, getMin(next, visit | (1 << next)) + arr[here][next]);
    }

    return ret;
}


int main() {
    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }
    memset(cache, -1, sizeof(cache));

    cout << getMin(0, 1);
    
    return 0;
}