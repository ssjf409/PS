#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<vector<char>> input_v;
vector<int> result_v;


bool check(int index, int num) {
    int sum = num;
    for(int i = 0; i <= index; i++) {
        sum += result_v[index - i];
        if(sum > 0) {
            if(input_v[index][index - i] == '+') continue;
            else return false;
        } else if(sum < 0) {
            if(input_v[index][index - i] == '-') continue;
            else return false;
        } else if(sum == 0) {
            if(input_v[index][index - i] == '0') continue;
            else return false;
        }
    }
    return true;
}

bool dfs(int index, int depth) {
    if(depth == 0) return true;


    if(input_v[index][index] == '-') {
        for(int i = -1; i >= -10; i--) {    // 이분 탐색으로 바꿔야 시간초과 안 날거 같음
            if(check(index, i)) {
                
            }
        }
    } else if(input_v[index][index] == '+') {
        for(int i = 1; i <= 10; i++) {
            check(index, i);
        }
    } else if(input_v[index][index] == '0') {
        check(index, 0);
    }
    

}

int main() {
    int N;
    int cnt = N;
    string str;

    cin >> N >> str;
    for(int i = 0; i < N; i++) {
        vector<char> temp_v;
        for(int j = 0; j < N; j++) {
            temp_v.push_back('1');
        }
        input_v.push_back(temp_v);
        result_v.push_back(0);
    }
    int str_index = 0;
    for(int i = 0; i < N; i++) {
        for(int j = i; j < N; j++) {
            input_v[i][j] = str[str_index++];
        }
    }

    // for(int i = 0; i < N; i++) {
    //     for(int j = 0; j < N; j++) {
    //         cout << input_v[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    dfs(0, N);
    
    return 0;
}