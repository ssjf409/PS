#include <iostream>
#include <string>

using namespace std;

int main() {
    int N;
    cin >> N;
    string str;
    int num = 0;

    for(int i = 0; i < N; i++) {
        cin >> str;
        for(int j = 0; j < str.size(); j++) {
            if(str[j] == '(') {
                num++;
            } else if(str[j] == ')') {
                num--;
            }
            if(num < 0) {
                break;
            }
        }

        if(num == 0) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
        num = 0;
    }
    
    return 0;
}