#include <iostream>
using namespace std;
int main() {
    string str;
    cin >> str;
    
    bool flag = true;
    if(str.size() > 0 && !(str[0] == '1' || str[0] == '2')) flag = false;
    
    for(int i = 1; i < str.size(); i++) {
        if(str[i - 1] == '1' && str[i] == '1') {
            flag = false;
            break;
        } else if(!(str[i] == '1' || str[i] == '2')) {
            flag = false;
            break;
        }
    }
    if(str.back() == '1') flag = false;

    if(flag) {
        cout << "true";
    } else {
        cout << "false";
    }

	return 0;
}