#include <iostream>
#include <vector>

#define MAX 30

using namespace std;

int arr[MAX + 1][2];

int main() {

    arr[1][0] = 1;
    arr[1][1] = 0;
    arr[2][0] = 0;  
    arr[2][1] = 1;
    for(int i = 3 ; i <= MAX; i++) {
        arr[i][0] = arr[i - 2][0] - arr[i - 1][0];
        arr[i][1] = arr[i - 2][1] - arr[i - 1][1];
    }

    int x;
    cin >> x;


    int cnt = 1;
    int max_cnt = 0;
    int max_n = 1;

    for(int i = 1; i <= x; i++) {
        cnt = 1;
        for(int j = 2; j <= MAX; j++) {
            int temp = arr[j][0] * x + arr[j][1] * i;
            if(temp < 0) {
                break;
            }
            cnt++;
        }
        if(cnt > max_cnt) {
            max_cnt = cnt;
            max_n = i;
        }
    }

    cout << max_cnt << '\n';

    for(int j = 1; j < max_cnt; j++) {
        cout << arr[j][0] * x + arr[j][1] * max_n << ' ';
    }
    cout << arr[max_cnt][0] * x + arr[max_cnt][1] * max_n;

    return 0;
}