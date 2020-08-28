#include <iostream>
#include <stack>

using namespace std;

int main() {
    string str, target, result = "";
    cin >> str >> target;

    stack<char> s;
    stack<char> temp;
    stack<int> lastIndex;

    int index = 0;
    for(int i = 0; i < str.size(); i++) {
        char c = str[i];
        if(c == target[0]) {
            s.push(c);
            if(index != 0) {
                lastIndex.push(index);
                index = 0;
            }
            index++;
            if(target.size() == 1) {
                s.pop();
            }
            
        } else if(c == target[index]) {
            if(index == target.size() - 1) {
                for(int j = 0; j < target.size() - 1; j++) {
                    s.pop();
                }
                if(lastIndex.empty()) {
                    index = 0;
                } else {
                    index = lastIndex.top();
                    lastIndex.pop();
                }
            } else {
                s.push(c);
                index++;
            }
        } else {
            while(!s.empty()) {
                temp.push(s.top());
                s.pop();
            }
            while(!temp.empty()) {
                result += temp.top();
                temp.pop();
            }
            index = 0;
            result += c;
        }
    }

    while(!s.empty()) {
        temp.push(s.top());
        s.pop();
    }
    while(!temp.empty()) {
        result += temp.top();
        temp.pop();
    }


    if(result == "") {
        cout << "FRULA";
    } else {
        cout << result;
    }

    return 0;
}