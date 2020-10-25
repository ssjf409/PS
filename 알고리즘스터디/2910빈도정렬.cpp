#include <iostream>
#include <map>

using namespace std;

int main() {
    int N, C;
    cin >> N >> C;

    map<int, int> m;
    map<int, int>::iterator iter;

    int a;
    for(int i = 0; i < N; i++) {
        cin >> a;
        if(m[a] == 0) {
            m[a] = 1;
        } else {
            m[a]++;
        }
    }

    for(int i = 1000; i > 0; i--) {
        for(iter = m.begin(); iter != m.end(); iter++) {
            if(iter->second == i) {
                for(int j = 0; j < iter->second; j++) {
                    cout << iter->first << ' ';
                }
            }
        }
    }


    return 0;
}