/*#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main() {
    int N;
    int num;
    
    cin >> N;

    int cnt = N;

    int max = 0;

    stack<int> s;
    queue<char> plus_minus;

    for(int i = 0; i < N; i++) {
        cin >> num;
        if(num > max) {
            for(int j = 0; j < num - max; j++) {
                plus_minus.push('+');
            }
            plus_minus.push('-');
            max = num;
            
        } else if (num < max) {
            plus_minus.push('-');
            
        }

    }

    int len = plus_minus.size();
    for(int i = 0; i < len; i++) {
        cout << plus_minus.front() << '\n';
        plus_minus.pop();
    }
    cout << cnt;

    return 0;
}
*/

#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main() {
    int N;
    int num;
    
    cin >> N;


    int max = 0;
    int sequ_num = 0;

    queue<char> plus_minus;
    stack<int> sequ;

    for(int i = 0; i < N; i++) {
        cin >> num;
        
        

        while(num > sequ_num) {
            sequ.push(++sequ_num);
            plus_minus.push('+');
            //cout << sequ_num << '\n';
        }

        if(num == sequ.top()) {
            sequ.pop();
            plus_minus.push('-');
        } else if(num < sequ.top()) {
            cout << "NO";
            return 0;
        }
        
        
        

    }

    int len = plus_minus.size();
    for(int i = 0; i < len; i++) {
        cout << plus_minus.front() << '\n';
        plus_minus.pop();
    }

    return 0;
}