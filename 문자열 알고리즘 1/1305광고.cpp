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

int main() {
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    int N;
    cin >> N;
    string str;
    cin >> str;
    vector<int> pi = getPi(str);

    cout << pi.size() - pi.back();

    return 0;
}