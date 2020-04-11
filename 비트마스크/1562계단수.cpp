// #include <iostream>
// #define MAX 10
// #define MOD 1000000000

// using namespace std;

// int N;
// int cache[10][100][1 << 10];

// int getCaseCnt(int start, int length, int visit) {
//     if(length == N) {
//         if(visit == (1 << 10) -1) return 1;
//         else return 0;
//     }
//     int& ret = cache[start][length][visit];
//     if(ret != -1) return ret;

//     ret = 0;

//     if(start >= 1) {
//         ret += getCaseCnt(start - 1, length + 1, visit | 1 << (start - 1));
//     }
//     if(start <= 8) {
//         ret += getCaseCnt(start + 1, length + 1, visit | 1 << (start + 1));
//     }


//     return ret = ret % MOD;
// }

// int main() {
//     cin >> N;
//     int sum = 0;
//     for(int i = 1; i <= 9; i++) {
//         sum += getCaseCnt(i, 1, 1 << i);
//         sum %= MOD;
//     }

//     cout << sum;
//     return 0;
// }