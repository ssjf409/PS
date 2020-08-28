#include <iostream>
#include <vector>

using namespace std;

int main() {
    string str;
    vector<int> alphaCnt(26, 0);

    cin >> str;

    for(int i = 0; i < str.size(); i++) {
        alphaCnt[str[i] - 'a']++;
    }

    for(int i = 0; i < 26; i++) {
        cout << alphaCnt[i] << ' ';
    }
    

    return 0;
}