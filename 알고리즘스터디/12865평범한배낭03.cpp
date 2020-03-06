#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    if(a.first == b.first) {
        return a.second > b.second;
    }
    return a.first < b.first;
}

int main() {
    int N, K;
    cin >> N >> K;

    vector<pair<int, int>> input_v(N + 1);
    input_v[0].first = 0;
    input_v[0].second = 0;
    for(int i = 1; i <= N; i++) {
        cin >> input_v[i].first >> input_v[i].second;
    }

    // sort(input_v.begin(), input_v.end(), compare);

    int arr[N+1][K+1] = {};

    for(int i = 1; i <= N; i++) {
        for(int weight = 0; weight <= K; weight++) {
            if(input_v[i].first <= weight) {
                if(input_v[i].second + arr[i-1][weight - input_v[i].first] > arr[i - 1][weight]) {
                    arr[i][weight] = input_v[i].second + arr[i-1][weight - input_v[i].first];
                } else {
                    arr[i][weight] = arr[i - 1][weight];
                }
            } else {
                arr[i][weight] = arr[i - 1][weight];
            }
        }
    }



    // for(int i = 0; i <= N; i++) {
    //     for(int j = 0; j <= K; j++) {
    //         cout << arr[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    cout << arr[N][K];

    
    // vector<int> temp(K + 1 , 0);
    // vector<int> result(K + 1, 0);
    // for(int i = 1; i <= N; i++) {
    //     for(int weight = 0; weight <= K; weight++) {
    //         if(input_v[i].first <= weight) {
    //             if(input_v[i].second + temp[weight - input_v[i].first] > temp[weight]) {
    //                 result[weight] = input_v[i].second + temp[weight - input_v[i].first];
    //             } else {
    //                 result[weight] = temp[weight];
    //             }
    //         } else {
    //             result[weight] = temp[weight];
    //         }
    //     }

    //     temp = result;
    // }

    // cout << result[K];


    return 0;
}