#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    string str;
    cin >> str;

    vector<string> subfix;

    for(int i = 0; i < str.size(); i++) {
        subfix.push_back(str.substr(i));
    }

    sort(subfix.begin(), subfix.end());

    for(int i = 0; i < subfix.size(); i++) {
        cout << subfix[i] << '\n';
    }

    return 0;
}