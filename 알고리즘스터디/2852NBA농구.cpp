#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    int flag = 0; // 1번팀은 음수로, 2번 팀은 양수로
    int before_time = 0;

    int sum_of_time_1 = 0;
    int sum_of_time_2 = 0;

    for(int i = 0; i < N; i++) {
        int temp;
        string str;
        cin >> temp >> str;

        int now_time = (str[0] - '0') * 60 * 10 + (str[1] - '0') * 60 + (str[3] - '0') * 10 + (str[4] - '0');

        if(flag < 0 ) {
            sum_of_time_1 += now_time - before_time;
        } else if(flag > 0) {
            sum_of_time_2 += now_time - before_time;
        }
        before_time = now_time;
        if(temp == 1) {
            flag--;
        } else if(temp == 2){
            flag++;
        }
    }

    if(flag < 0 ) {
        sum_of_time_1 += 48 * 60 - before_time;
    } else if(flag > 0) {
        sum_of_time_2 += 48 * 60 - before_time;
    }

    // cout << sum_of_time_1 / 60 << ':' << sum_of_time_1 % 60 << '\n';
    // cout << sum_of_time_2 / 60 << ':' << sum_of_time_2 % 60;
    
    if(sum_of_time_1 / 60 >= 10) {
        cout << sum_of_time_1 / 60;
    } else {
        cout << '0' << sum_of_time_1 / 60;
    }
    cout << ':';
    if(sum_of_time_1 % 60 >= 10) {
        cout << sum_of_time_1 % 60;
    } else {
        cout << '0' << sum_of_time_1 % 60;
    }
    cout << '\n';

    
    if(sum_of_time_2 / 60 >= 10) {
        cout << sum_of_time_2 / 60;
    } else {
        cout << '0' << sum_of_time_2 / 60;
    }
    cout << ':';
    if(sum_of_time_2 % 60 >= 10) {
        cout << sum_of_time_2 % 60;
    } else {
        cout << '0' << sum_of_time_2 % 60;
    }
    

    return 0;
}