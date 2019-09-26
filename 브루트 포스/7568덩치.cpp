#include <iostream>
#include <vector>

using namespace std;


int main() {
    vector<pair<int,int>> p;
    int N;
    int first;
    int second;
    int cnt = 1;


    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> first;
        cin >> second;
        p.push_back(make_pair(first,second));
    }

    //cout << "??" << endl;

    for(int i = 0; i < p.size(); i++) {
        cnt = 1;
        for(int j = 0; j < p.size(); j++) {
            if(p[i].first < p[j].first && p[i].second < p[j].second) {
                cnt++;
            }
        }
        cout << cnt << ' ';
    }
    return 0;
}