#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

string str1, str2;

int cache[1001][1001];

int getLCS(int idx1, int idx2) {
    if(idx1 == str1.size() || idx2 == str2.size()) return 0;

    int& ret = cache[idx1][idx2];
    if(ret != -1) return ret;

    return ret = max(max(getLCS(idx1 + 1, idx2), getLCS(idx1, idx2 + 1)), getLCS(idx1 + 1, idx2 + 1) + (str1[idx1] == str2[idx2]));
}

int main() {
    cin >> str1 >> str2;

    memset(cache, -1, sizeof(cache));

    cout << getLCS(0, 0);

    return 0;
}