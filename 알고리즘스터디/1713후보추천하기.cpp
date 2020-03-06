#include <iostream>
#include <deque>

using namespace std;

int main() {
    int N, recom;
    cin >> N >> recom;

    deque<pair<int, int>> dq;

    for(int i = 0; i < recom; i++) {
        int input_num;
        cin >> input_num;
        if(dq.size() < N) {
            int j;
            for(j = 0; j < dq.size(); j++) {
                if(dq[i].first == input_num) {
                    dq[i].second++;
                    break;
                }
            }
            if(j == dq.size()) {
                dq.push_back(make_pair(input_num, 1));
            }
        } else {
            int j;
            int min_index;
            int min = 9999999;
            for(j = 0; j < dq.size(); j++) {
                if(dq[i].first == input_num) {
                    dq[i].second++;
                    cout << "dq[i].second : " << dq[i].second << '\n';
                    break;
                } else if(dq[i].second < min){
                    min = dq[i].second;
                    min_index = j;
                }
            }
            if(j == dq.size()) {
                
                
            }

        }

    }

    for(int i = 0; i < dq.size(); i++) {
        cout << dq[i].first << ' ';
    }
    
    return 0;
}