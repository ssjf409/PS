#include <iostream>
#include <cstring>
#define MAX 1000

using namespace std;

int N;
int arr[MAX];
int cache[MAX];
int cache2[MAX];

int lis(int start) {
    int& ret = cache[start];
    if(ret != -1) return ret;

    ret = 1;

    for(int next = start - 1; next >= 0 ; next--) {
        if(arr[start] > arr[next]) {
            ret = max(ret, lis(next) + 1);
        }
    }

    return ret;
}


int lis2(int start) {
    int& ret = cache2[start];
    if(ret != -1) return ret;

    ret = 1;

    for(int next = start + 1; next < N; next++) {
        if(arr[start] > arr[next]) {
            ret = max(ret, lis2(next) + 1);
        }
    }

    return ret;
}

int getLis(int start) {
    
    return lis(start) + lis2(start) - 1;
}



int main() {
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    memset(cache, -1, sizeof(cache));
    memset(cache2, -1, sizeof(cache2));

    int maxLen = 0;
    for(int begin = 0; begin < N; begin++) {
        maxLen = max(maxLen, getLis(begin)); 
    }

    cout << maxLen;
    
    return 0;
}