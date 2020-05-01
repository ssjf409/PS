#include <iostream>

using namespace std;


int main() {

    string str;
    cin >> str;
    cout << str.substr(2, 0) << endl;
    cout << str.substr(2, 1) << endl;
    cout << str.substr(2, 2) << endl;

    return 0;
}