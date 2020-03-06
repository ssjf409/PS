#include <iostream>
#include <vector>

using namespace std;

bool pickupClose(const vector<vector<int>>& circle, vector<vector<bool>>& check, int i, int j) {
    bool flag = false;
    if(i == 0) {
        if(circle[i][j] == circle[i + 1][j]) {
            check[i][j] = true;
            check[i + 1][j] = true;
            flag = true;
        } 
    } else if(i == circle.size() - 1) {
        if(circle[i][j] == circle[i - 1][j]) {
            check[i][j] = true;
            check[i - 1][j] = true;
            flag = true;
        }      
    } else {
        if(circle[i][j] == circle[i + 1][j]) {
            check[i][j] = true;
            check[i + 1][j] = true;
            flag = true;
        } 
        if(circle[i][j] == circle[i - 1][j]) {
            check[i][j] = true;
            check[i - 1][j] = true;
            flag = true;
        }      
    }
    if(j == 0) {
        if(circle[i][j] == circle[i][circle[0].size() - 1]) {
            check[i][j] = true;
            check[i][circle[0].size() - 1] = true;
            flag = true;
        }
        if(circle[i][j] == circle[i][j + 1]) {
            check[i][j] = true;
            check[i][j + 1] = true;
            flag = true;
        }
    } else if(j == circle[0].size() - 1) {
        if(circle[i][j] == circle[i][0]) {
            check[i][j] = true;
            check[i][0] = true;
            flag = true;
        }
        if(circle[i][j] == circle[i][j - 1]) {
            check[i][j] = true;
            check[i][j - 1] = true;
            flag = true;
        }
    } else {
        if(circle[i][j] == circle[i][j + 1]) {
            check[i][j] = true;
            check[i][j + 1] = true;
            flag = true;
        }
        if(circle[i][j] == circle[i][j - 1]) {
            check[i][j] = true;
            check[i][j - 1] = true;
            flag = true;
        }
    }
    return flag;
}

int main() {
    int N, M, T;
    cin >> N >> M >> T;

    vector<vector<int>> circle(N, vector<int>(M));
    vector<int> temp(M);


    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> circle[i][j];
        }
    }
    
    int x, d, k;
    for(int i = 0; i < T; i++) {
        cin >> x >> d >> k;

        for(int j = 2; j <= N; j++) {
            if(j % x == 0) {
                
                temp = circle[j - 1];
                if(d == 0) {
                    for(int s = 0; s < M; s++) {
                        circle[j - 1][s] = temp[(s + M - k) % M];
                    }
                } else {
                    for(int s = 0; s < M; s++) {
                        circle[j - 1][s] = temp[(s + k) % M];
                    }
                }
            }
        }

        vector<vector<bool>> check(N, vector<bool>(M, false));
        

        bool changeFlag = false;
        for(int j = 0; j < N; j++) {
            for(int s = 0; s < M; s++) {
                if(circle[j][s] && pickupClose(circle, check, j, s)) {
                    changeFlag = true;
                }
            }
        }

        // cout << "=====================\n";
        for(int j = 0; j < N; j++) {
            for(int s = 0; s < M; s++) {
                // cout << check[j][s] << ' ';
                if(check[j][s]) {
                    circle[j][s] = 0;
                }
            }
            // cout << '\n';
        }

        if(!changeFlag) {
            double sum = 0;
            double average;
            int cnt = 0;
            for(int j = 0; j < N; j++) {
                for(int s = 0; s < M; s++) {
                    if(circle[j][s]) {
                        sum += circle[j][s];
                        cnt++;
                    }
                }
            }
            average = sum / cnt;
            for(int j = 0; j < N; j++) {
                for(int s = 0; s < M; s++) {
                    if(circle[j][s]) {
                        if(circle[j][s] < average) circle[j][s]++;
                        else if(circle[j][s] > average) circle[j][s]--;
                    }
                }
            }
        }

        
        // cout << "=====================\n";
        // for(int j = 0; j < N; j++) {
        //     for(int s = 0; s < M; s++) {
        //         cout << check[j][s] << ' ';
        //     }
        //     cout << '\n';
        // }

        // cout << "=====================\n";
        // for(int j = 0; j < N; j++) {
        //     for(int s = 0; s < M; s++) {
        //         cout << circle[j][s] << ' ';
        //     }
        //     cout << '\n';
        // }

        
    }

    int sum = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            sum += circle[i][j];
        }
    }
    
    cout << sum;


    return 0;
}