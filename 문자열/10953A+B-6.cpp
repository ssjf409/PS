#include <iostream>
#include <string>

using namespace std;

int main() {
    int N;
    cin >> N;
    while(N--) {
        string str;
        cin >> str;
        cout << str[0] - '0' + str[2] - '0' << '\n';

    }

    return 0;
}