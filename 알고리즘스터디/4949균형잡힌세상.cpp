#include <iostream>
#include <string>

using namespace std;

int main() {
    string str;
    int small_brace = 0;
    int big_brace = 0;

    while(true){
        cin >> str;
        if(str[0] == '.') {
            break;
        }
        for(int i = 0; i < str.size(); i++) {
            if(str[i] == '(') {
                small_brace++;
            } else if (str[i] == '[') {
                big_brace++;
            } else if (str[i] == ')') {
                small_brace--;
            } else if (str[i] == ']') {
                big_brace--;
            }


            if(small_brace < 0 || big_brace < 0) {
                cout << "no\n";
                small_brace = 0;
                big_brace = 0;
                break;
            }
            if(str[i] == '.' && i + 1 == str.size()) {
                if(small_brace == 0 && big_brace == 0) {
                    cout << "yes\n";
                    small_brace = 0;
                    big_brace = 0;
                }
            }
            
        }
    }

    return 0;
}