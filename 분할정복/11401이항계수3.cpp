#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<long long> up_floor = {1, 1};
    vector<long long> down_floor;

    for(int i = 2; i <= N; i++) {
        down_floor.push_back(1);
        for(int j = 1; j < i; j++) {
            down_floor.push_back((up_floor[j - 1] + up_floor[j]) % 1000000007);
        }
        down_floor.push_back(1);
        up_floor = down_floor;
        down_floor.clear();
    }

    cout << up_floor[K];
    return 0;
}