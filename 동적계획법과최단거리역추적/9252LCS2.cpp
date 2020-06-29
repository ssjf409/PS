#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

string str1, str2;
string result;
int cache[1001][1001];

int getLCS(int idx1, int idx2) {
    if(idx1 == str1.size() || idx2 == str2.size()) return 0;

    int& ret = cache[idx1][idx2];
    if(ret != -1) return ret;

    return ret = max(max(getLCS(idx1 + 1, idx2), getLCS(idx1, idx2 + 1)), getLCS(idx1 + 1, idx2 + 1) + (str1[idx1] == str2[idx2]));
}

// void reconstruct(int idx1, int idx2) {
//     if(idx1 == str1.size() || idx2 == str2.size()) return;

//     if(str1[idx1] == str2[idx2]) {
//         result += str1[idx1];
//         reconstruct(idx1 + 1, idx2 + 1);
//     } else if(cache[idx1 + 1][idx2] >= cache[idx1][idx2 + 1]) {
//         reconstruct(idx1 + 1, idx2);
//     } else {
//         reconstruct(idx1, idx2 + 1);
//     }
// }

int main() {
    cin >> str1 >> str2;

    memset(cache, -1, sizeof(cache));

    cout << getLCS(0, 0) << '\n';

    int N = 8;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cout << cache[i][j] << ' ';
        }
        cout << '\n';
    }
    // reconstruct(0, 0);
    // cout << result;


    return 0;
}