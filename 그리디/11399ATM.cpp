#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> v;

    for(int i = 0; i < N; i++) {
        int k;
        cin >> k;
        v.push_back(k);
    }

    sort(v.begin(), v.end());
    int length = v.size();
    int sum = 0;

    for(int i = 0; i < length; i++) {
        sum += v[i] * (length- i);
    }

    cout << sum;

    return 0;
}