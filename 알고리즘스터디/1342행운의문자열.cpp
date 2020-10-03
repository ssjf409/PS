#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    string str;
    cin >> str;

    int cnt = 0;


    sort(str.begin(), str.end());

    do {
        bool flag = false;
        for(int i = 1; i < str.size(); i++) {
            if(str[i - 1] == str[i]) {
                flag = true;
                break;
            }
        }
        if(!flag) {
            cnt++;
        }
    }while(next_permutation(str.begin(), str.end()));

    cout << cnt;

    return 0;
}