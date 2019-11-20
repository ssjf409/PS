#include <iostream>
#include <stack>
#include <string>


using namespace std;

int main() {

    string str;
    stack<char> s;

    while(true) {
        getline(cin, str);


        if(str.size() == 1 && str[0] == '.') {
            return 0;
        }
        for(int i = 0; i < str.size(); i++) {
            char c = str[i];
            if(c == '[' || c == '(') {
                s.push(c);
                
            } else if (c == ']') {
                if(s.empty()) {
                    s.push(c);
                    //cout << "no\n";
                    break;
                } else if(s.top() != '[') {
                    s.push(c);
                    //cout << "no\n";
                    break;
                } else {
                    s.pop();
                }
            } else if (c == ')') {
                if(s.empty()) {
                    s.push(c);
                    //cout << "no\n";
                    break;
                } else if(s.top() != '(') {
                    s.push(c);
                    //cout << "no\n";
                    break;
                } else {
                    s.pop();
                }
            }
        }

        if(s.empty()) {
            cout << "yes\n";
        } else {
            cout << "no\n";
        }


        while(!s.empty()) {
            s.pop();
        }
    }
    return 0;
}




// #include <iostream>
// #include <stack>
// #include <string>
// #include <cstdio>

// using namespace std;

// int main() {
//     string str;

//     stack<char> s;

//     while(true) {
//         getline(cin, str);
//         for(i)
//     }    
//     return 0;
// }