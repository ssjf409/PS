#include <iostream>

using namespace std;

int main() {
    int N;
    string str;
    cin >> N;
    cin >> str;
    int sum = 0;
    for(int i = 0; i < str.size(); i++) {
        sum += str[i] - '0';
    }

    cout << sum;
    
    return 0;
}