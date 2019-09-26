#include <iostream>
//#include <algorithm>
#include <cstdio>

using namespace std;



int main() {
    int N;
    cin >> N;
    int arr[10001] = {0};
    int number;

    for(int i = 0; i < N; i++) {
        scanf("%d", &number);
        arr[number]++;
    }

    for(int i = 1; i <= 10000; i++) {
        if(arr[i]) {
            for(int j = 0; j < arr[i]; j++) {
                printf("%d\n", i);
            }
        }
    }
    

    return 0;
}