#include <iostream>
#include <string>

using namespace std;

int main() {
    string str;
    getline(cin, str);

    bool wordStart = false;
    int cnt = 0;
    for(int i = 0; i < str.size(); i++) {
        if(str[i] != ' ') wordStart = true;
        else if(wordStart) {
            wordStart = false;
            cnt++;
        }
    }
    if(wordStart) {
        cnt++;
    }
    
    cout << cnt;

    return 0;
}