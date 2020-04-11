#include <iostream>
#include <cstring>


using namespace std;

long long cache[31][31];

long long getCaseNum(int w, int h) {
    long long& ret = cache[w][h];
    if(ret != -1) return ret;
    if(w == 0 && h == 0) return 1;
    
    long long whole = 0;
    long long half = 0;
    if(w > 0) {
        whole = getCaseNum(w - 1, h + 1);
    }
    if(h > 0) {
        half = getCaseNum(w, h - 1);
    }
    ret = whole + half;

    return ret;
}


int main() {
    int N;
    while(true) {
        cin >> N;
        if(N == 0) break;
        memset(cache, -1, sizeof(cache));
        cout << getCaseNum(N, 0) << '\n';
    }
    return 0;
}