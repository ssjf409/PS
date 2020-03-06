#include <iostream>
#include <vector>
#include <string>

using namespace std;

int buho[10][10];
vector<int> ans;
int N;

bool check(int index) {
    int sum = 0;
    for(int i = index; i >= 0; i--) {
        sum += ans[i];
        if(buho[i][index] == 0) {
            if(sum != 0) return false;
        }
        if(buho[i][index] < 0) {
            if(sum >= 0) return false;
        }
        if(buho[i][index] > 0) {
            if(sum <= 0) return false;
        }
    }
    return true;
}

bool dfs(int index) {
    if(index == N) return true;
    
    if(buho[index][index] == 0) {
        ans[index] = 0;
        return check(index) && dfs(index + 1);
    }
    for(int i = 1; i <= 10; i++) {
        ans[index] = buho[index][index] * i;
        if(check(index) && dfs(index + 1)) {
            return true;
        }
    }
    return false;
}

int main() {

    cin >> N;
    ans.resize(N);
    
    
    for(int i = 0; i < N; i++) {
        for(int j = i; j < N; j++) {
            char c;
            cin >> c;
            if(c == '-') {
                buho[i][j] = -1;
            }
            if(c == '+') {
                buho[i][j] = 1;
            }
            if(c == '0') {
                buho[i][j] = 0;
            }
            
            
        }
    }

    dfs(0);

    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << ' ';
    }


    return 0;
}