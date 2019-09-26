#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    int max = 0;
    cin >> N;

    vector<int> v(N+1);
    

    for(int i = 0; i < N; i++) {
        vector<int> temp(i+1);
        for(int j = 0; j <= i; j++) {
            cin >> temp[j];
        }

        if(i == 0) {
            v[i] = temp[i];
            continue;
        }

        
        //마지막
        //v[i] = v[i-1] + temp[i]; 

        for(int j = i; j >= 1; j--) {
            if(v[j-1] > v[j]) {
                v[j] = v[j-1] + temp[j];
            } else {
                v[j] = v[j] + temp[j];
            }
        }

        
        //첫번째
        v[0] += temp[0];

        
        // for(int i = 0; i < N; i++) {
        //     cout << v[i] << ' ';
        // }
        // cout << '\n';        

    }

    for(int i = 0; i < v.size(); i++) {
        if (v[i] > max) {
            max = v[i];
        }
    }

    cout << max;


    return 0;
}