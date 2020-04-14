#include <iostream>
#include <cstring>
#define MAX 1000

using namespace std;

string str1, str2;

int cache[MAX + 2][MAX + 2];


int getCnt(int str1Index, int str2Index) {

    int& ret = cache[str1Index + 1][str2Index + 1];
    if(ret != -1) return ret;

    ret = 1;

    for(int next = str1Index + 1; next < str1.size(); next++) {
        int tIndex = str2.find(str1[next], str2Index + 1);
        if(tIndex == string::npos) continue;
        ret = max(ret, getCnt(next, tIndex) + 1);
    }
    
    return ret;
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> str1 >> str2;

    memset(cache, -1, sizeof(cache));
    cout << getCnt(-1, -1) - 1;

    return 0;
}