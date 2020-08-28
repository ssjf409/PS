#include <iostream>
#include <vector>

using namespace std;

int main() {
    string str;
    cin >> str;

    vector<int> index(26, -1);

    for(int i = 0; i < str.size(); i++) {
        if(index[str[i] - 'a'] == -1) index[str[i] - 'a'] = i;
    }

    for(int i = 0; i < 26; i++) {
        cout << index[i] << ' ';
    }

    return 0;
}