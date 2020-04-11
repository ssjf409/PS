#include <iostream>
#include <cstring>
#define MAX 1000

using namespace std;

int N;
int arr[MAX];
int cache1[MAX][MAX];
int cache2[MAX];


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


int lis(int start, int end) {
    int& ret = cache1[start][end];
    if(ret != -1) return ret;

    ret = 1;
    
    for(int next = start + 1; next < end; next++) {
        if(arr[start] < arr[next]) {
            int maxLen = 0;
            for(int i = end; i < N; i++) {
                maxLen = max(maxLen, lis2(i));
            }
            ret = max(ret, lis(next, end) + maxLen + 1);
        }
    }
    return ret;
}



int main() {
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    memset(cache1, -1, sizeof(cache1));
    memset(cache2, -1, sizeof(cache2));
    
    // int maxLen2 = 0;
    // for(int begin = 0; begin < N; begin++) {
    //     maxLen2 = max(maxLen2, lis2(begin));
    // }

    int maxLen = 0;
    for(int begin = 0; begin < N; begin++) {
        for(int end = begin; end < N; end++) {
            maxLen = max(maxLen, lis(begin, end));
        }
    }


    cout << maxLen;
    return 0;
}