#include <iostream>
#include <vector>
#include <cctype>

using namespace std;

int main() {
    string str;
    cin >> str;

    vector<int> alphaCnt(26, 0);
    
    for(int i = 0; i < str.size(); i++) {
        if(isupper(str[i])) {
            alphaCnt[str[i] - 'A']++;
        } else {
            alphaCnt[str[i] - 'a']++;
        }
    }

    int maxValue = 0;
    bool isDouble = true;
    int maxIndex = -1;
    for(int i = 0; i < 26; i++) {
        if(alphaCnt[i] > maxValue) {
            isDouble = false;
            maxIndex = i;
            maxValue = alphaCnt[i];
        } else if(alphaCnt[i] == maxValue) {
            isDouble = true;
        }
    }

    if(isDouble) {
        cout << '?';
    } else {
        cout << char(maxIndex + 'A');
    }

    return 0;
}