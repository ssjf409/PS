#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#define MAX 1000

using namespace std;

string str1, str2;


int cache[MAX][MAX];


int getCnt(int idx1, int idx2) {

    if(idx1 == str1.size() || idx2 == str2.size()) return 0;

    int& ret = cache[idx1][idx2];
    if(ret != -1) return ret;


    return ret = max(getCnt(idx1 + 1, idx2), max(getCnt(idx1, idx2 + 1), getCnt(idx1 + 1, idx2 + 1) + (str1[idx1] == str2[idx2])));
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> str1 >> str2;

    memset(cache, -1, sizeof(cache));
    cout << getCnt(0, 0);

    return 0;
}