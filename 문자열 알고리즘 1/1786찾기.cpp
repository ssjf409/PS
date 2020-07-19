#include <iostream>
#include <vector>
#include <string>

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

vector<int> kmp(string s, string p) {
    vector<int> ret;
    vector<int> pi = getPi(p);
    int n = s.size();
    int m = p.size();
    int j = 0;

    for(int i = 0; i < n; i++) {
        while(j > 0 && s[i] != p[j]) {
            j = pi[j - 1];
        }
        if(s[i] == p[j]) {
            if(j == m - 1) {
                ret.push_back(i - m + 1);
                j = pi[j];
            } else {
                j++;
            }
        }
    }
    return ret;
}


int main() {
    string text, pattern;
    getline(cin, text);
    getline(cin, pattern);
    vector<int> answer = kmp(text, pattern);
    cout << answer.size() << '\n';
    for(const auto& el : answer) {
        cout << el + 1 << ' ' ;
    }


    return 0;
}