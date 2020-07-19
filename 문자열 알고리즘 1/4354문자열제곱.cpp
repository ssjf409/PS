#include <iostream>
#include <vector>
#include <string>
#define INF 987654321;

using namespace std;

vector<int> getPi(string p) {
    int m = p.size();
    int j = 0;
    vector<int> pi(m, 0);
    
    for(int i = 1; i < m; i++) {
        while(j > 0 && p[i] != p[j]) {
            j = pi[j - 1];
        }
        if(p[i] == p[j]) {
            pi[i] = ++j;
        }
    }
    return pi;
}


int main() {
    string str;
    while(true) {
        getline(cin, str);
        if(str == ".") break;
        vector<int> pi = getPi(str);

        for(int i = 0; i < pi.size(); i++) {
            cout << pi[i];
        }
        cout << endl;

        int cnt = 0;
        for(int i = 0; i < pi.size(); i++) {
            if(!pi[i]) cnt++;
            else break;
        }
        cout << (int)(pi.size() / cnt) << '\n';


        // int len = 1;
        // for(int i = 1; i < pi.size(); i++) {
        //     if(pi[i - 1] != pi[i] - 1) {
        //         len = i + 1;
        //     }
        // }
        // cout << pi.size() / len << '\n';
    }

    return 0;
}