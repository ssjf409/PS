// #include <iostream>
// #include <cstring>
// #define MAX 16
// #define INF 987654321

// using namespace std;

// int N;
// int arr[MAX][MAX];
// int cache[1 << MAX];
// int p;

// int getMin(, int visit, int cnt) {
//     if(cnt == p) return 0;
//     int& ret = cache[visit];
//     if(ret != -1) return ret;

//     ret = INF;

//     for(int i = 0; i < N; i++) {
//         if(!(visit & (1 << i))) continue;
//         for(int j = 0; j < N; j++) {
//             if(visit & (1 << j)) continue;
//             ret = min(ret, getMin())
//         }
//     }


//     return ret;
// }

// int main() {
//     cin >> N;
//     for(int i = 0; i < N; i++) {
//         for(int j = 0; j < N; j++) {
//             cin >> arr[i][j];
//         }
//     }
//     int visit = 0;
//     int cnt = 0;

//     string str;
//     cin >> str;
//     for(int i = 0; i < N; i++) {
//         if(str[i] == 'Y') {
//             visit |= (1 << i);
//             cnt++;
//         }
//     }
    
//     cin >> p;
//     if(p == 0) {
//         cout << 0;
//         return 0;
//     }

//     memset(cache, -1, sizeof(cache));

//     int minValue = INF;
//     for(int i = 0; i < N; i++) {
//         if(str[i] == 'Y') {
//             minValue = min(minValue, getMin(i, visit, cnt));
//         }
//     }

//     if(minValue == INF) {
//         cout << -1;
//     } else {
//         cout << minValue;
//     }

//     return 0;
// }