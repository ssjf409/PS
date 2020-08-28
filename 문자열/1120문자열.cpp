#include <iostream>
#define INF 987654321

using namespace std;

int main() {
    string str1, str2;
    cin >> str1 >> str2;

    int gap = str2.size() - str1.size();

    int maxCnt = INF;
    for(int i = 0; i <= gap; i++) {
        int cnt = 0;
        for(int j = 0; j < str1.size(); j++) {
            if(str1[j] != str2[j + i]) {
                cnt++;
            }
        }
        if(cnt < maxCnt) {
            maxCnt = cnt;
        }
    }

    cout << maxCnt;


    return 0;
}