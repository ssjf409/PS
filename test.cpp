#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#define MAX_N 10000

using namespace std;

int N, H[1000000];

int histogram(int s, int e) {
    if(s == e) return 0;
    if(s + 1 == e) return H[s];

    int mid = (s + e) / 2;
    int result = max(histogram(s, mid), histogram(mid, e));

    int w = 1, h = H[mid], l = mid, r = mid;
    
    while(r - l + 1 < e - s) {
        int p = l > s ? min(h, H[l - 1]) : -1;
        int q = r < e - 1 ? min(h, H[r + 1]) : -1;

        if(p >= q) {
            h = p;
            l--;
        } else {
            h = q;
            r++;
        }
        result = max(result, ++w * h);
    }
    return result;
}