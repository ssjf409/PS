#include <iostream>
#include <cstring>
#define MAX 1000

using namespace std;

int N;
int arr[MAX];
int cache[MAX];


int lisValue(int start) {
    int& ret = cache[start];
    if(ret != -1) return ret;

    ret = arr[start];

    for(int next = start + 1; next < N; next++) {
        if(arr[start] < arr[next]) {
            ret = max(ret, lisValue(next) + arr[start]);
        }
    }

    return ret;

}




int main() {
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
    memset(cache, -1, sizeof(cache));

    int maxValue = 0;
    for(int begin = 0; begin < N; begin++) {
        maxValue = max(maxValue, lisValue(begin));
    }
    cout << maxValue;

    return 0;
}