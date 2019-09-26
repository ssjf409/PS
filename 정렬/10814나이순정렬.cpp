#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

bool compare(pair<int, string> a, pair<int, string> b) {
    // if(a.first == b.first) {
    //     return 0;
    // } else {
    //     return a.first < b.first;
    // }
    return a.first < b.first;
}

int main() {
    int N;
    vector<pair<int,string>> v;
    int age;
    string name;

    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> age;
        cin >> name;
        v.push_back(make_pair(age, name));
    }

    stable_sort(v.begin(), v.end(), compare);
    

    for(int i = 0; i < v.size(); i++) {        
        cout << v[i].first << ' ' << v[i].second << '\n';
    }

    return 0;
}