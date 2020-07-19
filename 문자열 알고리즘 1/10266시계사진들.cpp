#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

vector<int> getPi(const vector<int>& itv2) {
    int m = itv2.size();
    int j = 0;
    vector<int> pi(m, 0);
    for(int i = 1; i < m; i++) {
        while(j > 0 && itv2[i] != itv2[j]) {
            j = pi[j - 1];
        }
        if(itv2[i] == itv2[j]) {
            pi[i] = ++j;
        }
    }
    return pi;
}


bool kmp(const vector<int>& itv1, const vector<int>& itv2) {
    vector<int> ret;
    vector<int> pi = getPi(itv2);
    int n = itv1.size();
    int m = itv2.size();
    int j = 0;


    for(int i = 0; i < n; i ++) {
        while(j > 0 && itv1[i] != itv2[j]) {
            j = pi[j - 1];
        }
        if(itv1[i] == itv2[j]) {
            if(j == m - 1) {
                ret.push_back(i - m + 1);
                return true;
                j = pi[j];
            } else {
                j++;
            }
        }
    }


    return false;
}

int main() {
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> hands1(n, 0);
    vector<int> hands2(n, 0);

    
    for(int i = 0; i < n; i++) {
        cin >> hands1[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> hands2[i];
    }

    sort(hands1.begin(), hands1.end());
    sort(hands2.begin(), hands2.end());
    hands1.push_back(hands1[0]);
    hands2.push_back(hands2[0]);


    vector<int> interval1(n * 2, 0);
    vector<int> interval2(n, 0);

    int temp;
    for(int i = 0; i < n - 1; i++) {
        temp = hands1[i + 1] - hands1[i];
        if(temp > 180000) interval1[i] = interval1[i + n] = 360000 - temp; 
        else interval1[i] = interval1[i + n] = temp;
        
        temp = hands2[i + 1] - hands2[i];
        if(temp > 180000) interval2[i] = 360000 - temp;
        else interval2[i] = temp;
    }

    temp = abs(hands1[n] - hands1[n - 1]);
    if(temp > 180000) interval1[n - 1] = interval1[n - 1 + n] = 360000 - temp;
    else interval1[n - 1] = temp;

    
    temp = abs(hands2[n] - hands2[n - 1]);
    if(temp > 180000) interval2[n - 1] = 360000 - temp;
    else interval2[n - 1] = temp;
    


    if(kmp(interval1, interval2)) {
        cout << "possible";
    } else {
        cout << "impossible";
    }



    return 0;
}