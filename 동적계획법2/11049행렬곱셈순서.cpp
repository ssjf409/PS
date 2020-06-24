#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define INF 987654321

using namespace std;

int cache[501][501];

int N;
vector<pair<int, int>> mat;
vector<int> sum;


int getMinOper(int start, int end) {
    if(start == end) return 0;
    if(start + 1 == end) {
        return mat[start].first * mat[start].second * mat[end].second;
    }

    int& ret = cache[start][end];
    if(ret != -1) return ret;

    ret = INF;

    for(int mid = start; mid < end; mid++) {
        ret = min(ret, getMinOper(start, mid) + getMinOper(mid + 1, end) + mat[start].first * mat[mid].second * mat[end].second);
    }

    return ret;
}


int main() {
    cin >> N;

    mat.assign(N, pair<int, int>());
    sum.assign(N, 0);

    for(int i = 0; i < N; i++) {
        cin >> mat[i].first >> mat[i].second;
    }

    memset(cache, -1, sizeof(cache));
    cout << getMinOper(0, N - 1);


    return 0;
}