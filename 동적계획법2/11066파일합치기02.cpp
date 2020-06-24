#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define INF 987654321

using namespace std;

int T;
vector<int> arr;
vector<int> sum;

int cache[501][501];


int getMinCnt(int start, int end) {

    int& ret = cache[start][end];
    if(ret != -1) return ret;

    if(start == end) return ret = 0;
    if(start + 1 == end) return ret = arr[start] + arr[end];

    ret = INF;

    for(int mid = start; mid < end; mid++) {
        ret = min(ret, getMinCnt(start, mid) + getMinCnt(mid + 1, end));
    }

    return ret += sum[end] - sum[start - 1];
}


int main() {
    cin >> T;
    for(int i = 0; i < T; i++) {

        int K;
        cin >> K;
        arr.assign(K + 1, 0);
        sum.assign(K + 1, 0);

        for(int j = 1; j <= K; j++) {
            cin >> arr[j];
            sum[j] = sum[j - 1] + arr[j];
        }

        memset(cache, -1, sizeof(cache));

        cout << getMinCnt(1, K) << '\n';
    }

    return 0;
}