#include <iostream>
#include <vector>

using namespace std;

int cnt_num[3] = {0};



void count_paper(vector<vector<int>> &input_v, int a, int b, int length) {

    int next_length = length / 3;
    
    int first_value = input_v[a][b];
    int clean_flag = true;

    for(int i = a; i < a + length; i++) {
        for(int j = b; j < b + length; j++) {
            if(first_value != input_v[i][j]) {
                clean_flag = false;
                break;
            }
        }
    }

    if(clean_flag) {
        cnt_num[first_value + 1]++;
        return;
    }

    for(int i = a; i < a + length; i += next_length) {
        for(int j = b; j < b + length; j += next_length) {
            count_paper(input_v, i, j, next_length);
        }
    }

}

int main() {
    int N, input;
    cin >> N;
    vector<vector<int>> input_v(N, vector<int>(N));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> input;
            input_v[i][j] = input;
        }
    }

    count_paper(input_v, 0, 0, input_v[0].size());

    cout << cnt_num[0] << '\n';
    cout << cnt_num[1] << '\n';
    cout << cnt_num[2] << '\n';
    return 0;
}