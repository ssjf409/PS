#include <iostream>
#include <cstring>
#include <string>
#define MAX 1000
#define ALPHA_SIZE 26
#define INF 987654321

using namespace std;


int arr[MAX][MAX];
int N, sum;
bool visit[MAX];

void getMin(int y, int acc, int condition, int value) {
    // cout << y << "   =========\n";
    if(y == N) {
        if(acc < sum) {
            sum = acc;
        }
        return;
    }
    if(y == condition) {
        visit[condition] = true;
        getMin(y + 1, acc + value, condition, value);
        visit[condition] = false;
        return;
    }

    for(int i = y + 1; i <= N; i++) {
        if(visit[i]) continue;
        visit[i] = true;
        getMin(y + 1, acc + arr[y][i], condition, value);
        visit[i] = false;
    }
}


int main() {
    int testCase;
    cin >> testCase;

    for(int tCaseNum = 0; tCaseNum < testCase; tCaseNum++) {
        string str;
        cin >> str;
        N = str.size();
        int iName[N];

        for(int i = 0; i < N; i++) {
            iName[i] = str[i] - 'A';
        }

        int hCnt;
        int vCnt;
        for(int i = 0; i < N; i++) { // i : 출발 j 도착
            for(int j = 0; j < N; j++) { 
                if(i == j) continue;

                if(iName[j] > iName[i]) {
                    hCnt = min(iName[j] - iName[i], ALPHA_SIZE - iName[j] + iName[i]);
                } else {
                    hCnt = min(iName[i] - iName[j], ALPHA_SIZE - iName[i] + iName[j]);
                }

                if(i > j) {
                    vCnt = min(i - j, N - j + i);
                } else {
                    vCnt = min(j - i, N - i + j);
                }

                arr[i][j] = hCnt + vCnt;
            }
        }


        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                cout << arr[i][j] << '\t';
            }
            cout << '\n';
        }
        
        for(int i = 0; i < N; i++) {
            sum = INF;
            visit[i] = true;
            if(i < N / 2) {
                
                getMin(0, 0, i, iName[i] + i);
            } else {
                getMin(0, 0, i, iName[i] + N - i);
            }
            visit[i] = false;

        }
        cout << sum << '\n';

    }

    

    return 0;
}