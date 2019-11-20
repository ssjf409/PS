#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main() {
    int C, N;
    cin >> C;
    for(int i = 0; i < C; i++) {
        cin >> N;
        vector<int> v(N);
        int sum = 0;
        for(int j = 0; j < N; j++) {
            cin >> v[j];
            sum += v[j];
        }
        double average = (double) sum / (double) N;

        int cnt = 0;
        for(int j = 0; j < N; j++) {
            if((double)v[j] > average) {
                cnt++;
            }
        }
        printf("%.3lf%%\n", ((double)cnt / (double)N) * 100);

    }
    return 0;
}