#include <iostream>
#include <vector>
#include <queue>

using namespace std;



int main() {
    int N;
    cin >> N;

    vector<int> val_v;
    vector<vector<int>> v_pre;

    vector<int> temp_v;

    for(int i = 0; i < N; i++) {
        int val;
        cin >> val;
        val_v.push_back(val);
        while(true){
            int temp;
            cin >> temp;
            if(temp == -1) {
                v_pre.push_back(temp_v);
                temp_v.clear();

                break;
            }
            
            temp_v.push_back(temp);
        }
    }

    for(int i = 0; i < v_pre.size(); i++) {
        
    }

    return 0;
}