#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987654321

using namespace std;

vector<long long> hist;

int getMaxArea(int left, int right) {
    if(left == right) return hist[left];

    int mid = (left + right) / 2;
    
    long long ret = max(getMaxArea(left, mid), getMaxArea(mid + 1, right));

    long long lo = mid, hi = mid + 1;
    long long height = min(hist[lo], hist[hi]);

    ret = max(ret, height * 2);

    while(left < lo || hi < right) {
        if(hi < right && (lo == left || hist[lo - 1] < hist[hi + 1])) {
            height = min(height, hist[++hi]);
        } else {
            height = min(height, hist[--lo]);
        }
        ret = max(ret, height * (hi - lo + 1));
    }

    return ret;
}

int main() {
    int N;
    while(true) {
        cin >> N;
        hist.assign(N, 0);
        for(int i = 0; i < N; i++) {
            cin >> hist[i];
        }

        cout << getMaxArea(0, N - 1) << '\n';
    }




    return 0;
}