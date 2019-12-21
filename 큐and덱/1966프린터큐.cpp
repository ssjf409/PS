#include <iostream>
#include <queue>

using namespace std;

int main() {

    int test_case;
    cin >> test_case;

    for(int i = 0; i < test_case; i++) {
        int N, M;
        cin >> N >> M;
        queue<pair<int, int>> q;

        int cnt = 0;

        for(int j = 0; j < N; j++) {
            int temp;
            cin >> temp;
            q.push(make_pair(temp,j));
        }

        while(!q.empty()) {
            pair<int, int> temp = q.front();
            q.pop();

            int q_length = q.size();
            bool flag = false;
            for(int j = 0; j < q_length; j++) {
                if(temp.first < q.front().first) {
                    flag = true;
                }
                q.push(q.front());
                q.pop();
            }
            
            if(flag) {
                q.push(temp);
            } else {
                cnt++;
                if(temp.second == M) {
                    cout << cnt << '\n';
                }
            }
        }
        


        

    }
    

    return 0;
}