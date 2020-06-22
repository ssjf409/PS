#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath>
// #include <cstring>

using namespace std;

int N, K;
vector<string> num;
vector<bool> visited;
int cnt = 0;

map<string, int> m;

int printFraction(string str) {
    if(str.size() == 1) {
        return (str[0] - '0') % K;
    }


    if(m.find(str) != m.end()) return m[str];

    int length = str.size() < 8 ? str.size() : 8;
    int remain = stoi(str.substr(0, length)) % K;
    int ret = printFraction(to_string(remain) + str.substr(length));
    m.insert({str, ret});

    return ret;
}


void getNumDivSeq(int n, string str) {
    if(n == N) {
        // cout << str << '\n';
        if(printFraction(str) == 0) {
            cnt++;
        };
    }

    

    for(int i = 0; i < N; i++) {
        if(visited[i]) continue;
        visited[i] = true;
        getNumDivSeq(n + 1, str + num[i]);
        visited[i] = false;
    }
}

long long fac(int num) {
    if(num == 1) return 1;
    return num * fac(num - 1);
}

int main() {
    cin >> N;

    num.assign(N, "");
    visited.assign(N, false);


    for(int i = 0; i < N; i++) {
        cin >> num[i];
    }
    cin >> K;

    getNumDivSeq(0, "");

    if(cnt == 0) {
        cout << "0/1";
    } else {
        long long denominator = fac(N);
        long long tempDeno = denominator;
        int tempCnt = cnt;

        for(int i = 2; i <= cnt; i++) {
            if(tempDeno % i == 0 && tempCnt % i == 0) {
                tempDeno /= i;
                tempCnt /= i;
            }
        }

        cout << tempCnt << '/' << tempDeno;
    }


    return 0;
}