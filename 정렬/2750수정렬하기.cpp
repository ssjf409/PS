#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    int arr[N];

    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr,arr+N);

    for(int i = 0; i < N-1; i++) {
        cout << arr[i] << endl;
    }
    cout << arr[N-1];

    return 0;
}