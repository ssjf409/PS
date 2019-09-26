#include <iostream>
#include <vector>

using namespace std;

int main() {
    // int N;
    // cin >> N;
    // vector<int> v(N+1);
    // vector<int> acc_v(N+1);

    // v[0] = 0;
    // acc_v[0] = 0;

    // for(int i = 1; i <= N; i++) {
    //     cin >> v[i];
    // }
    
    // acc_v[1] = v[1];
    // acc_v[2] = v[2];
    // // acc_v[3] = v[3];

    // for(int i = 3; i <= N; i++) {
    //     if(v[i - 2] > v[i - 1]) {
    //         acc_v[i] = acc_v[i - 3] + v[i - 2] + v[i];
    //     } else {
    //         acc_v[i] = acc_v[i - 3] + v[i - 1] + v[i];
    //     }
    // }

    // cout << acc_v[N];




    // int N;
    // cin >> N;
    // vector<int> v(N+1);
    // vector<int> acc_v(N+1);

    // bool flag = false;

    // v[0] = 0;
    // acc_v[0] = 0;
    // for(int i = 1; i <= N; i++) {
    //     cin >> v[i];
    // }
    

    // acc_v[1] = v[1];
    // for(int i = 2; i <= N; i++) {
    //     if(!flag && acc_v[i - 1] > acc_v[i - 2]) {
    //         acc_v[i] = acc_v[i - 1] + v[i];
    //         flag = true;
    //     } else {
    //         acc_v[i] = acc_v[i - 2] + v[i];
    //         flag = false;
            
    //     }
    // }

    // //cout << acc_v[N + 1];

    // for(int i = 1; i <= N; i++) {
    //     cout << acc_v[i] << ' ';
    // }


    int N;
    cin >> N;
    vector<pair<int, bool>> v(N+1);
    vector<int> acc_v(N+1);


    v[0].first = 0;
    v[0].second = false;

    for(int i = 1; i <= N; i++) {
        cin >> v[i].first;
        v[i].second = false;
    }


    acc_v[1] = v[1].first;
    for(int i = 2; i <= N; i++) {
        if(v[i - 1].second){
            acc_v[i] = acc_v[i - 2] + v[i].first;
            v[i].second = false;
        } else if(acc_v[i - 1] > acc_v[i - 2]) {
            acc_v[i] = acc_v[i - 1] + v[i].first;
            v[i].second = true;
        } else {
            acc_v[i] = acc_v[i - 2] + v[i].first;
            v[i].second = false;
        }
    }
    int max = acc_v[N];

    v[1].second = false;
    for(int i = 2; i <= N; i++) {
        if(v[i - 1].second){
            acc_v[i] = acc_v[i - 2] + v[i].first;
            v[i].second = false;
        } else if(acc_v[i - 1] > acc_v[i - 2]) {
            acc_v[i] = acc_v[i - 1] + v[i].first;
            v[i].second = true;
        } else {
            acc_v[i] = acc_v[i - 2] + v[i].first;
            v[i].second = false;
        }
    }
    if(acc_v[N] > max) {
        max = acc_v[N];
    }

    cout << max;


    // for(int i = 1; i <= N; i++) {
    //     cout << acc_v[i] << ' ';
    // }
    // cout << acc_v[N];

    return 0;
}