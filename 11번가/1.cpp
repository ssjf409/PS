#include <vector>

// failure function
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

// kmp
int kmp(string s, string p) {
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
                return i - m + 1;
                j = pi[j];
            } else {
                j++;
            }
        }
    }
    return -1;
}

int solution(string &S) {
    // check "aaa" case
    int findIdx = kmp(S, "aaa");
    if(findIdx != -1) return -1;

    // count a and others
    int aCnt = 0;
    int otherCnt = 0;
    for(unsigned int i = 0; i < S.size(); i++) {
        if(S[i] == 'a') {
            aCnt++;
        } else {
            otherCnt++;
        }
    }

    
    return (otherCnt + 1) * 2 - aCnt;
}
