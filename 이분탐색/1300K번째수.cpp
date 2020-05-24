// #include <iostream>
// #include <algorithm>
// #include <vector>
// #include <cmath>
// #define MAX 1000000000

// using namespace std;         GG

// bool compare(const long long& a, const long long& b) {
//     return a > b;
// }


// int main() {
//     int N, k;
//     cin >> N >> k;

//     vector<long long> arr(N + 1);

//     for(int i = 1; i <= N; i++) {
//         arr[i] = min(i * i, MAX);
//     }


//     int index = lower_bound(arr.begin(), arr.end(), k) - arr.begin();


//     vector<long long> res;
//     res.push_back(arr[index]);

//     for(int i = 1; i < index; i++) {
//         if(index + i > N) break;
//         res.push_back((index - i) * (index + i));
//         res.push_back((index - i) * (index + i));
//     }

//     for(int i = 1; i < index; i++) {
//         if(index + i - 1 > N) break;
//         res.push_back((index - i) * (index - 1 + i));
//         res.push_back((index - i) * (index - 1 + i));
//     }

//     sort(res.begin(), res.end(), compare);



//     int cnt = arr[index];

//     for(int i = 0; i < res.size(); i++) {
//         if(cnt == k) {
//             cout << res[i];
//             break;
//         }
//         cnt--;
//     }


//     return 0;
// }