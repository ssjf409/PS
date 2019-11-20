// ***************************
// * ** ** ** ** ** ** ** ** *
// ***************************
// ***   ******   ******   ***
// * *   * ** *   * ** *   * *
// ***   ******   ******   ***
// ***************************
// * ** ** ** ** ** ** ** ** *
// ***************************
// *********         *********
// * ** ** *         * ** ** *
// *********         *********
// ***   ***         ***   ***
// * *   * *         * *   * *
// ***   ***         ***   ***
// *********         *********
// * ** ** *         * ** ** *
// *********         *********
// ***************************
// * ** ** ** ** ** ** ** ** *
// ***************************
// ***   ******   ******   ***
// * *   * ** *   * ** *   * *
// ***   ******   ******   ***
// ***************************
// * ** ** ** ** ** ** ** ** *
// ***************************
#include <iostream>
#include <vector>

using namespace std;



vector<vector<char>> v_map;

void make_pattern(int a, int b, int N) {
    int interval = N / 3;

    for(int i = a + interval; i < a + interval + interval; i++) {
        for(int j = b + interval; j < b + interval + interval; j++) {
            v_map[i][j] = ' ';
        }
    }

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(interval >= 3) {
                make_pattern(a + i * interval, b + j * interval, interval);
            }
        }
    }

    
}

int main() {
    int N;
    cin >> N;
    
    vector<char> v(N, '*');

    for(int i = 0; i < N; i++) {
        v_map.push_back(v);
    }


    make_pattern(0, 0, N);

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cout << v_map[i][j];
        }
        cout << '\n';
    }

    return 0;
}