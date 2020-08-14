#include <iostream>
#include <vector>

using namespace std;

int N;
vector<long long> req;

inline long long getTotalBudget(long long mid) {
    long long ret = 0;
    for(const auto& el : req) {
        if(el > mid) ret += mid;
        else ret += el;
    }

    return ret;
}


int main() {
    cin >> N;
    req.resize(N);

    long long max = 0;
    for(int i = 0; i < N; i++) {
        cin >> req[i];

        if(req[i] > max) {
            max = req[i];
        }
    }

    long long low = 0, high = max;
    long long mid, M, result = 0;
    cin >> M;



    while(low <= high) {
        mid = (low + high) / 2;

        long long budget = getTotalBudget(mid);

        if(budget > M) {
            high = mid - 1;
        } else {
            result = mid;
            low = mid + 1;
        }
    }
    cout << result;

    return 0;
}