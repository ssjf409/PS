#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
/*
int n;
int cache[100], S[100];
// S[start]에서 시작하는 증가 부분 수열 중 최대 길이를 반환한다.
int lis2(int start) {
    int& ret = cache[start];
    if(ret != -1) return ret;
    // 항상 S[start]는 있기 때문에 길이는 최하 1
    ret = 1;
    for(int next = start + 1; next < n; ++next) {
        if(S[start] < S[next]) {
            ret = max(ret, lis2(next) + 1);
        }
    }
    return ret;
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> S[i];
    }

    memset(cache, -1, sizeof(cache));


    // 가장 처음 값을 기준으로 잡기 때문에 각각 호출해서 최대값을 구해야 한다.
    int maxLen = 0;
    for(int begin = 0; begin < n; ++begin) {
        maxLen = max(maxLen, lis2(begin));
    }

    cout << maxLen;
    return 0;
}
*/



/*
시작 위치 고정하기
위의 코드처럼 하면 무조건 첫 수로 시작위치가 고정된다.
하지만 아래 처럼 짜게 되면 시작 위치를 -1(음의 무한대)로 설정할 수 있게된다.
*/
int n;
int cache[101], S[100];
// S[start]에서 시작하는 증가 부분 수열 중 최대 길이를 반환한다.
int lis3(int start) {
    int& ret = cache[start + 1];
    if(ret != -1) return ret;
    // 항상 S[start]는 있기 때문에 길이는 최하 1
    ret = 1;
    for(int next = start + 1; next < n; ++next) {
        if(start == -1 || S[start] < S[next]) {
            ret = max(ret, lis3(next) + 1);
        }
    }
    return ret;
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> S[i];
    }

    memset(cache, -1, sizeof(cache));


    cout << lis3(-1) - 1;
    return 0;
}