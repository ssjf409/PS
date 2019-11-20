//https://marobiana.tistory.com/89

// #include <iostream>
// #include <vector>

// using namespace std;

// int main() {
//     int M, N;
//     cin >> M >> N;

//     vector<int> v_sosu;
//     vector<int> answer;

//     for(int i = 2; i <= N; i++) {
//         int j;
//         for(j = 0; j < v_sosu.size(); j++) {
//             if(i % v_sosu[j] == 0) {
//                 break;
//             }
//         }
//         if(j == v_sosu.size()) {
//             v_sosu.push_back(i);
//             answer.push_back(i);
//         }
//     }
//     int start_sosu_index;
//     for(int i = 0; i < answer.size(); i++) {
//         if(answer[i] == M) {
//             start_sosu_index = i;
//         }
//     }

//     for(int i = start_sosu_index; i < answer.size(); i++) {
//         cout << answer[i] << '\n';
//     }
    


//     return 0;
// }


#include <iostream>
#include <vector>

using namespace std;

int main() {

    int M, N;
    cin >> M >> N;

    vector<bool> v(N+1, false);
    vector<int> answer;

    int start_index = 0;
    
    for(int i = 2; i < v.size(); i++) {
        if(i == M) {
            start_index = answer.size();
        }

        if(v[i] == true) {
            continue;
        }
        for(int j = i; j < v.size(); j += i) {
            v[j] = true;
        }
        answer.push_back(i);
    }


    for(int i = start_index; i < answer.size(); i++) {
        cout << answer[i] << '\n';
    }


    return 0;
}