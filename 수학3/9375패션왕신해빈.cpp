#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int N;
    cin >> N;
    for(int i = 0; i < N; i++) {
        int test_case;
        cin >> test_case;
        vector<pair<string, int>> v;
        string str;
        for(int j = 0; j < test_case; j++) {
            cin >> str; // 버려
            cin >> str;
            for(int k = 0; k <= v.size(); k++) {
                if(k == v.size()) {
                    v.push_back(make_pair(str,1));
                }
                if(v[k].first == str) {
                    v[k].second++;
                    break;
                }
            }
        }
        int sum = 1;
        for(int i = 0; i < v.size(); i++) {
            sum *= v[i].second;
        }
        cout << sum - 1 << '\n';
    }
    return 0;
}