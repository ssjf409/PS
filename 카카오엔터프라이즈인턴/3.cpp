#include <iostream>
#include <vector>
#include <cstdio>
#define INF 987654321

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    double minLen = INF;
    double maxLen = -INF;
    
    vector<double> snack(N);
    double temp;
    for(int i = 0; i < N; i++) {
        cin >> snack[i];
        if(snack[i] < minLen) minLen = snack[i];
        if(snack[i] > maxLen) maxLen = snack[i];
    }


    double lo = 0.0;
    double hi = maxLen;
    double min;
    for(int i = 0; i < 100; i++) {
        min = (lo + hi) / 2.0;
        int cnt = 0;
        for(int j = 0; j < N; j++) {
            cnt += (int)(snack[j] / min);
        }
        if(cnt < K) {
            hi = min;
        } else if(cnt >= K) {
            lo = min;
        }
    }

    printf("%.2lf", min);
        
    




    
	return 0;
}