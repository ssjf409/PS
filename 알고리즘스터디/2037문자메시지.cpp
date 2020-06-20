#include <iostream>
#include <string>
#include <cctype>

using namespace std;


char group[8][2] = {{'A', 'C'}, {'D', 'F'}, {'G', 'I'}, {'J', 'L'}, {'M', 'O'}, {'P', 'S'}, {'T', 'V'}, {'W', 'Z'}};

int main() {
    int p, w;
    string str;
    cin >> p >> w;
    cin.ignore();
    getline(cin, str);

    int before = -1;
    int cnt = 0;
    bool flag = false;
    int ret = 0;

    for(int i = 0; i < str.size(); i++) {
        char temp = str[i];

        if(isalpha(temp)) {
            for(int j = 0; j < 8; j++) {
                if(temp >= group[j][0] && temp <= group[j][1]) {
                    if(before == j) flag = true;

                    cnt = (temp - group[j][0] + 1) * p;
                    before = j;
                }
            }
        } else {
            cnt = p;
            before = -1;
        }

        if(flag) cnt += w;
        ret += cnt;

        flag = false;
    }

    cout << ret;

    return 0;
}