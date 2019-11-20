#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> v(N);
    
    for(int i = 0; i < N; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    int first = v[0];
    int second = v[1];

    int gongyacksu;

    for(int i = second; i > 0; i--) {
        if(first % i == 0 && second % i == 0) {
            gongyacksu = i;
            break;
        }
    }

    for(int i = 2; i <= gongyacksu; i++) {
        if(gongyacksu % i == 0) { 
            cout << i << ' ';
        }
    }

    /*
    int range = v[1];

    
    for(int i = 2; i <= range; i++) {
        int mod = v[0] % i;

        for(int j = 1; j < v.size(); j++) {
            if((v[j] % i) != mod) {
                break;
            } else if(j == v.size() - 1) {
                cout << i << ' ';
            }
        }
        
    }
    */

    return 0;
}