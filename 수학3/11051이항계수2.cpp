#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<vector<int>> v;
    vector<int> temp = {1, 1};
    v.push_back(temp);
    v.push_back(temp);
    temp.clear();

    for(int i = 2; i <= N; i++) {
        int j;
        temp.push_back(1);
        for(j = 1; j < i; j++) {
            temp.push_back((v[i-1][j-1] + v[i-1][j]) % 10007);
            //cout << v[i-1][j-1] + v[i-1][j] << ' ';
        }
        //cout << '\n';
        if(j == i) {
            temp.push_back(1);
        }
        v.push_back(temp);
        temp.clear();
    }
    
    cout << v[N][K];

    return 0;
}