#include <iostream>

using namespace std;

int main() {
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);

    string str;
    cin >> str;

    for(int i = 0; i < str.size(); i++) {
        cout << str[i];
        if((i + 1) % 10 == 0) {
            cout << '\n';
        }
    }
    
    return 0;
}