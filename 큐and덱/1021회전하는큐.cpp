#include <iostream>
#include <deque>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    deque<int> q;

    for(int i = 1; i <= N; i++) {
        q.push_back(i);
    }

    int sum = 0;
   
    for(int i = 0; i < M; i++) {
        int temp;

        cin >> temp;
        for(int j = 0; j < q.size(); j++) {
            if(temp == q.front()) {
                if(j <= q.size() / 2) {
                    //cout << j << '\n';
                    sum += j;
                    q.pop_front();
                    break;
                } else {
                    //cout << q.size() - j << '\n';
                    sum += (q.size() - j);
                    q.pop_front();
                    break;
                }
            }
            q.push_back(q.front());
            q.pop_front();
        }
    }

    cout << sum << '\n';
    return 0;
}