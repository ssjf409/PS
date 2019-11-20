#include <iostream>
#include <string>

using namespace std;

int main() {

    int first_num = 0;
    int minus_sum = 0;
    int last_num;
    bool minus_start = false;

    string temp_str = "0";

    string str;
    cin >> str;

    for(int i = 0; i < str.size(); i++) {
        if(str[i] == '-' || str[i] == '+') {

            if(minus_start) { // 안되면 나중에 수정하자.
                minus_sum += stoi(temp_str);
            } else {
                first_num += stoi(temp_str);
            }

            
            if(str[i] == '-') {
                minus_start = true;
            }

            temp_str.clear();
        } else {
            temp_str += str[i];
            //cout << temp_str << '\n';
        }
    }
    if(minus_start) {
        last_num = -stoi(temp_str);
    } else {
        last_num = stoi(temp_str);
    }
    cout << first_num - minus_sum + last_num;



    return 0;
}