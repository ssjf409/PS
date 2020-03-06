#include <iostream>
#include <stack>

using namespace std;

int main() {
    int T;
    cin >> T;
    for(int i = 0 ; i < T; i++) {
        int N;
        int max_val = 0;
        long long sum = 0;

        cin >> N;

        stack<int> s;
        for(int j = 0; j < N; j++) {
            int input;
            cin >> input;
            if(input < max_val) {
                int top = s.top();
                while(!s.empty()) {
                    sum += (top - s.top());
                    s.pop();
                }
                max_val = input;
            } else if(input > max_val) {
                max_val = input;
            }
            s.push(input);
        }
        
        
        int top = s.top();
        while(!s.empty()) {
            if(top > s.top()) {
                sum += (top - s.top());
            }
            s.pop();
        }
        
        cout << sum << '\n';


    }
    return 0;
}