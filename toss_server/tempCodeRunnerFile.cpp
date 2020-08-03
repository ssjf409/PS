#include <iostream>
using namespace std;
int main() {
    string str;
    cin >> str;
    
    bool flag = true;
    for(int i = 1; i < str.size(); i++) {
        if(str[i - 1] == '1' && str[i] == '1') {
            flag = false;
            break;
        }
    }

    if(flag) {
        cout << "true";
    } else {
        cout << "false";
    }

	return 0;
}