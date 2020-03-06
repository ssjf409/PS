#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N;
vector<vector<int>> map_v;

struct value_cnt {
    int value = 0;
    int cnt = 0;
};

bool compare(value_cnt a, value_cnt b) {
    return a.value < b.value;
}

int get_val(int a1, int a2, int b1, int b2) {
    int start_i = min(a1, b1), start_j = min(a2, b2);
    int end_i = max(a1, b1), end_j = max(a2, b2);

    int sum = 0;
    for(int i = start_i; i <= end_i; i++) {
        for(int j = start_j; j <= end_j; j++) {
            sum += map_v[i][j];
        }
    }
    
    return sum;
}

int get_point_val(int a, int b) {

    vector<value_cnt> left_v;
    vector<value_cnt> right_v;

    int sum_ul_dr = 0;
    int sum_ur_dl = 0;

    //up_left and down_right
    //up_left
    for(int i = 0; i < a; i++) {
        for(int j = 0; j < b; j++) {
            int value = get_val(i, j, a, b);
            bool value_flag = false;
            for(int k = 0; k < left_v.size(); k++) {
                if(left_v[k].value == value) {
                    left_v[k].cnt++;
                    value_flag = true;
                    break;
                }
            }
            if(!value_flag) {
                value_cnt temp;
                temp.value = value;
                temp.cnt = 1;
                left_v.push_back(temp);
            }
        }
    }

    //down_right
    for(int i = a; i < N; i++) {
        for(int j = b; j < N; j++) {
            int value = get_val(i, j, a, b);
            bool value_flag = false;
            for(int k = 0; k < right_v.size(); k++) {
                if(right_v[k].value == value) {
                    right_v[k].cnt++;
                    value_flag = true;
                    break;
                }
            }
            if(!value_flag) {
                value_cnt temp;
                temp.value = value;
                temp.cnt = 1;
                right_v.push_back(temp);
            }
        }
    }
    
    sort(left_v.begin(), left_v.end(), compare);

    sort(right_v.begin(), right_v.end(), compare);
    
    for(int i = 0; i < left_v.size(); i++) {
        for(int j = 0; j < right_v.size(); j++) {
            if(left_v[i].value > right_v[j].value) {
                break;
            } else if(left_v[i].value == right_v[j].value) {
                sum_ul_dr += left_v[i].cnt * right_v[j].cnt;
                break;
            }
        }
    }
    
    // 초기화
    left_v.clear();
    right_v.clear();

    //up_right and down_left
    //up_right
    for(int i = 0; i < a; i++) {
        for(int j = b; j < N; j++) {
            int value = get_val(i, j, a, b);
            bool value_flag = false;
            for(int k = 0; k < left_v.size(); k++) {
                if(left_v[k].value == value) {
                    left_v[k].cnt++;
                    value_flag = true;
                    break;
                }
            }
            if(!value_flag) {
                value_cnt temp;
                temp.value = value;
                temp.cnt = 1;
                left_v.push_back(temp);
            }
        }
    }

    //down_left
    for(int i = a; i < N; i++) {
        for(int j = 0; j < b; j++) {
            int value = get_val(i, j, a, b);
            bool value_flag = false;
            for(int k = 0; k < right_v.size(); k++) {
                if(right_v[k].value == value) {
                    right_v[k].cnt++;
                    value_flag = true;
                    break;
                }
            }
            if(!value_flag) {
                value_cnt temp;
                temp.value = value;
                temp.cnt = 1;
                right_v.push_back(temp);
            }
        }
    }
    
    sort(left_v.begin(), left_v.end(), compare);

    sort(right_v.begin(), right_v.end(), compare);
    
    for(int i = 0; i < left_v.size(); i++) {
        for(int j = 0; j < right_v.size(); j++) {
            if(left_v[i].value > right_v[j].value) {
                break;
            } else if(left_v[i].value == right_v[j].value) {
                sum_ur_dl += left_v[i].cnt * right_v[j].cnt;
                break;
            }
        }
    }

    return sum_ul_dr + sum_ur_dl;


}

int main() {
    cin >> N;
    for(int i = 0; i < N; i++) {
        vector<int> temp_v(N);
        for(int j = 0; j < N; j++) {
            cin >> temp_v[i];
        }
        map_v.push_back(temp_v);
    }

    int sum = 0;
    for(int i = 1; i < N; i++) {
        for(int j = 1; j < N; j++) {
            sum += get_point_val(i, j);
        }
    }

    cout << sum;

    return 0;
}