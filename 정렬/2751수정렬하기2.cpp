#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;



int main() {
    int N;
    cin >> N;
    int arr[N];

    for(int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    sort(arr,arr+N);

    int i;
    for(i = 0; i < N-1; i++) {
        // cout << arr[i] << endl;
        printf("%d\n", arr[i]);
    }
    printf("%d", arr[i]);

    return 0;
}