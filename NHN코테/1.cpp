#include <iostream>
#include <vector>
using namespace std;
int main() {
    string str;
    cin >> str;
    vector<string> v(8);
    for(int i = 0; i < 8; i++) {
        v[i] = str.substr(0, 16);
        str = str.substr(16);
    }

    for(int i = 0; i < v.size(); i++) {
        int temp = 0;
        string bits16 = v[i];
        for(int j = 0; j < bits16.size(); j++) {
            temp <<= 1;
            temp += bits16[j] - '0';
        }
        cout << hex << temp;
        if(i != v.size() - 1) {
            cout << ":";
        }
    }
    cout << endl;


	return 0;
}