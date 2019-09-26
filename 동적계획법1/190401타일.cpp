#include <iostream>
#include <vector>


using namespace std;

int main() {
    
    int N;
    cin >> N;

    vector<int> v(N);
    v[0] = 1;
    v[1] = 2;

    for(int i = 2; i < N; i++) {
        v[i] = (v[i - 2] + v[i - 1]) % 15746 ;
    }

    cout << v[N - 1];


    return 0;
}