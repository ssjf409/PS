#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    deque<int> d;

    for(int i = 0; i < N; i++) {
        string str;
        cin >> str;

        int temp;

        if(str == "push_back") {
            cin >> temp;    
            d.push_back(temp);
            
        } else if(str == "push_front") {
            cin >> temp;
            d.push_front(temp);
            
        } else if(str == "front") {
            if(d.empty()) {
                cout << -1 << '\n';
            } else {
                cout << d.front() << '\n';
            }
        } else if(str == "back") {
            if(d.empty()) {
                cout << -1 << '\n';
            } else {
                cout << d.back() << '\n';
            }
        } else if(str == "size") {
            cout << d.size();
            cout << '\n';
        } else if(str == "empty") {
            if(d.empty()) {
                cout << 1 << '\n';
            } else {
                cout << 0 << '\n';
            }
        } else if(str == "pop_front") {
            if(d.empty()) {
                cout << -1 << '\n';
            } else {
                cout << d.front() << '\n';
                d.pop_front();
            }
        } else if(str == "pop_back") {
            if(d.empty()) {
                cout << -1 << '\n';
            } else {
                cout << d.back() << '\n';
                d.pop_back();
            }
        }
    }
    return 0;
}