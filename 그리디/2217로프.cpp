#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b) {
    return a > b;
}

int main() {
    int N;
    cin >> N;

    int max_weight = 0;

    vector<int> v(N);
    for(int i = 0; i < N; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end(), compare);

    for(int i = 0; i < N; i++) {

        int temp = v[i] * (i + 1);
        if(temp > max_weight) {
            max_weight = temp;
        }
    }

    cout << max_weight;

    return 0;
}