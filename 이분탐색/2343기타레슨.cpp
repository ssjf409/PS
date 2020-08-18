#include <iostream>
#include <vector>

using namespace std;

inline long long countBlueRay(const vector<int>& lesson, long long mid) {
    long long cnt = 1;
    long long temp = mid;
    for(const auto& el : lesson) {
        if(temp - el < 0) {
            temp = mid - el;
            cnt++;
        } else {
            temp -= el;
        }
    }

    return cnt;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> lesson(N);
    long long low = 0;
    for(int i = 0; i < N; i++) {
        cin >> lesson[i];
        if(low < lesson[i]) {
            low = lesson[i];
        }
    }

    long long high = 1000000000;
    long long mid, result;

    while(low < high) {
        mid = (low + high) / 2;

        long long blueRayNum = countBlueRay(lesson, mid);

        if(blueRayNum > M) {
            low = mid + 1;
        } else {
            result = mid;
            high = mid;
        }
    }

    cout << result;

    return 0;
}