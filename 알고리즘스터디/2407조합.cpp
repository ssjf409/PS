#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

long long cache[100][100];


long long Do(int n, int m) {
    if(n == 1 || m == 0) return 1;

    long long& ret = cache[n][m];
    if(ret != -1) return cache[n][m];
    ret = Do(n - 1, m - 1) + Do(n - 1, m);
    return ret;

}


int main() {
    
    memset(cache, -1, sizeof(cache));
    int n, m;
    cin >> n >> m;

    cout << Do(n, m);

    return 0;
}