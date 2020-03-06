#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N;
vector<vector<int>> map_v;

struct value_cnt_t {
    int value = 0;
    int cnt = 0;
};

bool compare(value_cnt_t a, value_cnt_t b) {
    return a.value < b.value;
}

int get_rect_val(int p1_i, int p1_j, int p2_i, int p2_j) {

    int start_i = min(p1_i, p2_i);
    int start_j = min(p1_j, p2_j);
    int end_i = max(p1_i, p2_i);
    int end_j = max(p1_j, p2_j);

    int tot_val = 0;

    for(int i = start_i; i <= end_i; i++) {
        for(int j = start_j; j <= end_j; j++) {
            tot_val += map_v[i][j];
        }
    }

    return tot_val;
}

int get_point_rect(int point_i, int point_j) {

    vector<value_cnt_t> value_left_cnt_v;
    vector<value_cnt_t> value_right_cnt_v;

    int sum = 0;

    //up_left
    for(int i = 0; i < point_i; i++) {
        for(int j = 0; j < point_j; j++) {
            int value = get_rect_val(point_i - 1, point_j - 1, i, j); // point_i - 1, point_j - 1을 기준으로
            bool flag_value_find = false;
            for(int k = 0; k < value_left_cnt_v.size(); k++) {
                if(value_left_cnt_v[k].value == value) {
                    value_left_cnt_v[k].cnt++;
                    flag_value_find = true;
                    break;
                }
            }
            if(!flag_value_find) {
                value_cnt_t temp_t;
                temp_t.value = value;
                temp_t.cnt = 1;
                value_left_cnt_v.push_back(temp_t);
            }
        }
    }
    
    // for(int i = 0; i < value_left_cnt_v.size(); i++) {
    //     cout << value_left_cnt_v[i].value << ' ';
    // }
    // cout << '\n';

    //down_right
    for(int i = point_i; i < N; i++) {
        for(int j = point_j; j < N; j++) {
            int value = get_rect_val(point_i, point_j, i, j); // point_i - 1, point_j - 1을 기준으로
            bool flag_value_find = false;
            for(int k = 0; k < value_right_cnt_v.size(); k++) {
                if(value_right_cnt_v[k].value == value) {
                    value_right_cnt_v[k].cnt++;
                    flag_value_find = true;
                    break;
                }
            }
            if(!flag_value_find) {
                value_cnt_t temp_t;
                temp_t.value = value;
                temp_t.cnt = 1;
                value_right_cnt_v.push_back(temp_t);
            }
        }
    }
    
    // for(int i = 0; i < value_right_cnt_v.size(); i++) {
    //     cout << value_right_cnt_v[i].value << ' ';
    // }
    // cout << '\n';


    sort(value_left_cnt_v.begin(), value_left_cnt_v.end(), compare);
    sort(value_right_cnt_v.begin(), value_right_cnt_v.end(), compare);

    for(int i = 0; i < value_left_cnt_v.size(); i++) {
        for(int j = 0; j < value_right_cnt_v.size(); j++) {
            if(value_left_cnt_v[i].value < value_right_cnt_v[j].value) {
                break;
            } else if(value_left_cnt_v[i].value == value_right_cnt_v[j].value) {
                sum += value_left_cnt_v[i].cnt * value_right_cnt_v[j].cnt;
            }

        }
    }
    // cout << sum << '\n';
    
    value_left_cnt_v.clear();
    value_right_cnt_v.clear();

    // vector<pair<int, int>> value_left_cnt_v;
    // vector<pair<int, int>> value_right_cnt_v;


    //up_right
    for(int i = 0; i < point_i; i++) {
        for(int j = point_j; j < N; j++) {
            int value = get_rect_val(point_i - 1, point_j, i, j); // point_i - 1, point_j - 1을 기준으로
            bool flag_value_find = false;
            for(int k = 0; k < value_left_cnt_v.size(); k++) {
                if(value_left_cnt_v[k].value == value) {
                    value_left_cnt_v[k].cnt++;
                    flag_value_find = true;
                    break;
                }
            }
            if(!flag_value_find) {
                value_cnt_t temp_t;
                temp_t.value = value;
                temp_t.cnt = 1;
                value_left_cnt_v.push_back(temp_t);
            }
        }
    }
    
    // for(int i = 0; i < value_left_cnt_v.size(); i++) {
    //     cout << value_left_cnt_v[i].value << ' ';
    // }
    // cout << '\n';

    //down_left
    for(int i = point_i; i < N; i++) {
        for(int j = 0; j < point_j; j++) {
            int value = get_rect_val(point_i, point_j - 1, i, j); // point_i - 1, point_j - 1을 기준으로
            bool flag_value_find = false;
            for(int k = 0; k < value_right_cnt_v.size(); k++) {
                if(value_right_cnt_v[k].value == value) {
                    value_right_cnt_v[k].cnt++;
                    flag_value_find = true;
                    break;
                }
            }
            if(!flag_value_find) {
                value_cnt_t temp_t;
                temp_t.value = value;
                temp_t.cnt = 1;
                value_right_cnt_v.push_back(temp_t);
            }
        }
    }

    
    // for(int i = 0; i < value_right_cnt_v.size(); i++) {
    //     cout << value_right_cnt_v[i].value << ' ';
    // }
    // cout << '\n';


    sort(value_left_cnt_v.begin(), value_left_cnt_v.end(), compare);
    sort(value_right_cnt_v.begin(), value_right_cnt_v.end(), compare);

    for(int i = 0; i < value_left_cnt_v.size(); i++) {
        for(int j = 0; j < value_right_cnt_v.size(); j++) {
            if(value_left_cnt_v[i].value < value_right_cnt_v[j].value) {
                break;
            } else if(value_left_cnt_v[i].value == value_right_cnt_v[j].value) {
                sum += value_left_cnt_v[i].cnt * value_right_cnt_v[j].cnt;
            }

        }
    }

    return sum;

}

int main() {
    cin >> N;
    for(int i = 0; i < N; i++) {
        vector<int> temp_v;
        for(int j = 0; j < N; j++) {
            int input;
            cin >> input;
            temp_v.push_back(input);
        }
        map_v.push_back(temp_v);
    }

    int cnt = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cnt += get_point_rect(i, j);
        }
    }

    // cout << get_point_rect(1,1);
    
    cout << cnt;

    return 0;
}