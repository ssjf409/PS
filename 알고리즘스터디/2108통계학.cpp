#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    int arr[8001] = {0};
    int temp;
    double sum = 0.0;
    vector<int> num;
    for(int i = 0; i < N; i++) {
        cin >> temp;
        sum += temp;
        num.push_back(temp);
        arr[temp + 4000]++;
    }

    double average = sum / N;
    if(average >= 0) {
        cout << int(average + 0.5) << '\n';
    } else {
        cout << int(average - 0.5) << '\n';
    }

    sort(num.begin(), num.end());
    cout << num[N / 2] << '\n';

    int ret;
    int cur = 0;
    bool second = false;
    for(int i = 0; i <= 8000; i++) {
        if(cur < arr[i]) {
            cur = arr[i];
            ret = i;
            second = false;
        } else if(cur == arr[i] && !second) {
            ret = i;
            second = true;
        }
    }
    cout << ret - 4000 << '\n';
    

    cout << num[N - 1] - num[0];
    return 0;
}