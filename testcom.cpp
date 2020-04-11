#include <iostream>

using namespace std;

int main() {
    int N, sum = 0;
    cin >> N;
    for(int i = 0; i < N; i++) {
        string str;
        cin >> str;
        bool flag = true;
        bool alpha[26] = {false,};
        
        alpha[str[0] - 'a'] = true;
        for(int j = 1; j < str.size(); j++) {
            if(str[i] == str[i - 1]) continue;
            if(!alpha[str[i] - 'a']) {
                alpha[str[i] - 'a'] = true;
            } else {
                flag = false;
                break;
            }
        }
        if(flag) {
            sum++;
        }
        
    }
    cout << sum;
    return 0;
}