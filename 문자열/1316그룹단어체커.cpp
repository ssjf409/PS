#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    int cnt = 0;
    while(N--) {
        string str;
        cin >> str;

        vector<bool> isVisited(26, false);
        bool isGroupWord = true;
        
        isVisited[str[0] - 'a'] = true;
        for(int i = 1; i < str.size(); i++) {
            if(str[i - 1] == str[i]) continue;
            if(isVisited[str[i] - 'a']) {
                isGroupWord = false;
                break;
            } else {
                isVisited[str[i] - 'a'] = true;
            }
        }
        if(isGroupWord) cnt++;

    }

    cout << cnt;

    return 0;
}