#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

int N;
vector<vector<int>> map_v;

// map<int, int> left_m;
// map<int, int> right_m;

map<int, int> get_left_val(int a, int b, int before_area, int length) {

}


int get_case_num(int a, int b) {

    //left_up
    map<int, int> left_m;
    left_m = get_left_val(a - 1, b - 1, map_v[a - 1][b - 1], 1);

    //right_down

    //right_up

    //left_down
}

int main() {
    cin >> N;
    for(int i = 0; i < N; i++) {
        vector<int> temp_v;
        for(int j = 0; j < N; j++) {
            int temp;
            cin >> temp;
            temp_v.push_back(temp);
        }
        map_v.push_back(temp_v);
    }

    int sum = 0;
    for(int i = 1; i < N - 1; i++) {
        for(int j = 1; j < N - 1; j++) {
            sum += get_case_num(i,j);
        }
    }

    return 0;
}