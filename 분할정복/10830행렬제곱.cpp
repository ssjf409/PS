#include <iostream>
#include <vector>

using namespace std;

// void show_mat(vector<vector<int>> &a) {
//     int length = a.size();
//     cout << "================\n";
//     for(int i = 0; i < length; i++) {
//         for(int j = 0; j < length; j++) {
//             cout << a[i][j] << ' ';
//         }
//         cout << '\n';
//     }
// }

vector<vector<long long>> mat_mul(vector<vector<long long>> &a, vector<vector<long long>> &b) {
    int length = a.size();

    vector<vector<long long>> output_v(length, vector<long long>(length));
    for(int i = 0; i < length; i++) {
        for(int j = 0; j < length; j++) {
            long long sum = 0;
            for(int k = 0; k < length; k++) {
                sum += (a[i][k] * b[k][j]) % 1000;
            }
            output_v[i][j] = sum % 1000;
        }
    }
    return output_v;
}

vector<vector<long long>> mat_pow(vector<vector<long long>> &a, long long b) {
    if(b == 1) {
        return a;
    }
    int length = a.size();
    vector<vector<long long>> temp_v(length, vector<long long>(length));

    if(b % 2 == 1) {
        vector<vector<long long>> temp_v2(length, vector<long long>(length));
        temp_v = mat_pow(a, b / 2);
        temp_v2 = mat_pow(a, b / 2 + 1);
        return mat_mul(temp_v, temp_v2);
    } else {
        temp_v = mat_pow(a, b / 2);
        return mat_mul(temp_v, temp_v);
    }

    // int length = a.size();
    // vector<vector<int>> unit_v(length, vector<int>(length, 0));
    
    // for(int i = 0 ; i < length; i++) {
    //     unit_v[i][i] = 1;
    // }
    

    // int cnt = 1;
    // while(cnt < b) {
    //     cnt += cnt;
    // }
    // cnt /= 2;
    // if(cnt == 0) {
    //     cnt = 1;
    // }

    // vector<bool> cnt_v;
    // for(int i = cnt, temp = b; i > 0; i /= 2) {
    //     if(temp >= i) {
    //         temp -= i;
    //         cnt_v.push_back(true);
    //     } else {
    //         cnt_v.push_back(false);
    //     }
    // }

    // // cout << "cnt_v : ";
    // // for(int i = 0; i < cnt_v.size(); i++) {
    // //     cout << cnt_v[i] << ' ';
    // // }

    // vector<vector<int>> temp_a = a;

    // for(int i = cnt_v.size() - 1; i >= 0; i--) {
    //     bool flag = cnt_v[i];
    //     if(!flag) {
    //         temp_a = mat_mul(temp_a, temp_a);
    //         continue;
    //     }

    //     unit_v = mat_mul(unit_v, temp_a);
    //     temp_a = mat_mul(temp_a, temp_a);

    // }


    // return unit_v;
    
}


int main() {
    int N;
    long long B;
    cin >> N >> B;

    vector<vector<long long>> input_v(N, vector<long long>(N));
    vector<vector<long long>> output_v;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> input_v[i][j];
        }
    }

    output_v = mat_pow(input_v, B);

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cout << output_v[i][j] << ' ';
        }
        cout << '\n';
    }


    return 0;
}