#include <iostream>
#include <cstring>
#define eMAX 100
#define pMAX 500
#define INF 987654321

using namespace std;

int N;
int M;
int arr[pMAX + 1];

int cache[pMAX + 1][pMAX + 1];

int getCnt(int start, int lastPos) {

    int& ret = cache[start][lastPos];
    if(ret != -1) return ret;

    ret = 1;

    for(int next = start + 1; next <= M; next++) {
        if(lastPos < arr[next]) {
            ret = max(ret, getCnt(next, arr[next]) + 1);
        }
    }

    return ret;
}



int main() {
    cin >> N;
    int index, input;

    M = 0;
    for(int i = 0; i < N; i++) {
        cin >> index;
        if(index > M) M = index;
        cin >> arr[index];
    }

    memset(cache, -1, sizeof(cache));

    int maxLine = getCnt(0, 0) - 1;
    cout << N - maxLine;

    return 0;
}