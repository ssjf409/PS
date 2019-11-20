#include <iostream>
#include <stack>

using namespace std;

int main() {
    int N;
    cin >> N;

    stack<int> s;

    int temp;
    for(int i = 0; i < N; i++) {
        cin >> temp;
        if(temp == 0) {
            s.pop();
            continue;
        }
        s.push(temp);
    }
    
    //cout << "���� ������ : " << s.size() << '\n';
    

    int sum = 0;
    int length = s.size();
    for(int i = 0; i < length; i++) {
        //cout << "ž ���� : " <<s.top() << '\n';
        sum += s.top();

        s.pop();
    }

    cout << sum;
    return 0;
}