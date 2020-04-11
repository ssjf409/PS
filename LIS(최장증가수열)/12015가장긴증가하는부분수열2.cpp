#include <iostream>
#include <cstring>
#define MAX 1000

using namespace std;

int N;
int arr[MAX];
int cache[MAX];

int lis(int start) {
    int& ret = cache[start];
    if(ret != -1) return ret;

    ret = 1;

    for(int next = start + 1; next < N; next++) {
        if(arr[start] < arr[next]) {
            ret = max(ret, lis(next) + 1);
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

    int maxLen = 0;

    int value[N];
    for(int begin = 0; begin < N; begin++) {
        value[begin] = max(maxLen, lis(begin));
    }


    for(int i = 0; i < N; i++) {
        cout << value[i] << ' ';
    }
    // cout << maxLen;
    
    return 0;
}