#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

int main() {
    string type;
    cin >> type;

    cin.ignore();
    string str;
    getline(cin, str);
    

    string temp = "";
    string val = "";

    for(int i = 0; i < str.size(); i++) {
        char c = str[i];
        if(c == ' ') continue;
        if(c == ',' || c == ';') {
            reverse(temp.begin(), temp.end());
            for(int j = 0; j < temp.size(); j++) {
                if(temp[j] == '[') {
                    temp[j] = ']';
                } else if(temp[j] == ']') {
                    temp[j] = '[';
                }
            }
            cout << type << temp << ' ' << val << ";\n";
            temp = "";
            val = "";
            continue;
        }

        if(isalpha(c)) {
            val += c;
        } else {
            temp += c;
        }
    }


    return 0;
}