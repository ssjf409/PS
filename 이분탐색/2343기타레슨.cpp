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
    if(temp < 0) cnt++;

    return cnt;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> lesson(N);
    long long sum = 0;
    for(int i = 0; i < N; i++) {
        cin >> lesson[i];
        sum += lesson[i];
    }

    long long low = 0, high = sum;
    long long mid, result;

    while(low < high) {
        mid = (low + high) / 2;

        long long BlueRayNum = countBlueRay(lesson, mid);

        if(BlueRayNum == M) {
            int max = 0;
            for(int i = 0; i < lesson.size(); i++) {
                if(max < lesson[i]) max = lesson[i];
            }
            result = max;
            break;
        }

        if(BlueRayNum > M) {
            low = mid + 1;
        } else {
            result = mid;
            high = mid;
        }
    }

    cout << result;

    return 0;
}