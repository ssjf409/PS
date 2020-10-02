#include <vector>
#include <algorithm>
#include <cmath>

#define MAX_VALUE 1000000000


int solution(vector<int> &A) {
    int N = A.size();
    vector<bool> visited(N + 1, false);
    vector<int> cnt(N + 1, 0);

    vector<int> notChoosed;
    vector<int> overlapped;

    // count overlapped numbers
    // and check not used numbers
    for(int i = 0; i < N; i++) {
        visited[A[i]] = true;
        cnt[A[i]]++;
    }

    // make a list of overlapped numbers
    // and a list of not used numbers
    for(int i = 1; i <= N; i++) {
        if(cnt[i] > 1) {
            for(int j = 0; j < cnt[i] - 1; j++) {
               overlapped.push_back(i);
            }
        }
        if(!visited[i]) {
            notChoosed.push_back(i);
        }
    }

    sort(overlapped.begin(), overlapped.end());
    sort(notChoosed.begin(), notChoosed.end());

    // accumulate each of gaps
    int sum = 0;
    for(unsigned int i = 0; i < overlapped.size(); i++) {
        sum += abs(overlapped[i] - notChoosed[i]);
        if(sum > MAX_VALUE) return -1;
    }

    return sum;
}
