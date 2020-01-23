#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> cnt_v;

bool compare(int a, int b) {
    return cnt_v[a] > cnt_v[b];
}

int main() {
    int N;
    cin >> N;
    vector<vector<int>> input_v;
    vector<int> desc_order(N+1);

    int result_cnt = 0;

    for(int i = 0; i <= N; i++) {
        vector<int> temp;
        input_v.push_back(temp);
        cnt_v.push_back(0);
    }
    
    for(int i = 1; i < N; i++) {
        int input_a, input_b;
        cin >> input_a >> input_b;
        input_v[input_a].push_back(input_b);
        input_v[input_b].push_back(input_a);
        cnt_v[input_a]++;
        cnt_v[input_b]++;
    }

    for(int i = 0; i <= N; i++) {
        desc_order[i] = i;
    }

    sort(desc_order.begin() + 1, desc_order.end(), compare);

    // for(int i = 1; i < desc_order.size(); i++) {
    //     cout << desc_order[i] << ' ';
    // }

    for(int i = 1; i < desc_order.size(); i++) {
        int x = desc_order[i];
        // int temp = cnt_v[x];
        if(cnt_v[x] <= 0) {
            continue;
        }

        result_cnt++;
        cnt_v[x] = 0;

        for(int j = 0; j < input_v[x].size(); j++) {
            cnt_v[input_v[x][j]]--;
        }
    }

    cout << result_cnt;

    return 0;
}