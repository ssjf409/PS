#include <iostream>
#include <cstring>

using namespace std;

int N;
int arr[30 + 1];
long long cache[30 + 1];


long long getCnt(int length) {
    if(length == 0) return 1;
    long long& ret = cache[length];
    if(ret != -1) return ret;

    ret = 0;
    if(length >= 2) ret += 3 * getCnt(length - 2);
    for(int i = 4; i <= length; i += 2) {
        ret += 2 * getCnt(length - i);
    }


    return ret;
}

int main() {
    cin >> N;

    memset(cache, -1, sizeof(cache));
    cout << getCnt(N);
    
    return 0;
}