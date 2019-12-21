#include <iostream>
#include <string>
#include <string.h>
#include <deque>

using namespace std;

int main() {
    int T;
    cin >> T;
    for(int i = 0; i < T; i++) {
        string cmd;
        int length;
        string arr;
        bool right_flag = true;

        deque<int> q;


        cin >> cmd >> length >> arr;


        string trim_arr = arr.substr(1, arr.size()-2);
        
        char *str_buff = new char[1000];
        strcpy(str_buff, trim_arr.c_str());
        char *tok = strtok(str_buff, ",");
        while(tok != NULL) {
            q.push_back(atoi(tok));
            // cout << atoi(tok) << '\n';
            tok = strtok(NULL, ",");
        }


        for(int j = 0; j < cmd.size(); j++) {
            if(cmd[j] == 'R') {
                if(right_flag) {
                    right_flag = false;
                } else {
                    right_flag = true;
                }
            } else if (cmd[j] == 'D') {
                
                if(q.empty()) {
                    cout << "error\n";
                    break;
                }
                if(right_flag) {
                    q.pop_front();
                } else {
                    q.pop_back();
                }
            }
        }


        if(!q.empty()) {
            cout << '[';
            int q_length = q.size();
            if(right_flag) {
                for(int j = 0; j < q_length - 1; j++) {
                    cout << q.front() << ',';
                    q.pop_front();
                }
                cout << q.front() << "]\n";
            } else {
                for(int j = 0; j < q_length - 1; j++) {
                    cout << q.back() << ',';
                    q.pop_back();
                }
                cout << q.back() << "]\n";
            }
        }

        

    }
    return 0;
}