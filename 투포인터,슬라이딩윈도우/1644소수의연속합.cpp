#include <iostream>
#include <vector>
#include <cmath>

#define FIRSTPRIM 2

using namespace std;




int main() {
    int N;
    cin >> N;

    vector<int> pNum;

    pNum.push_back(FIRSTPRIM);
    for(int num = 3; num <= N; num++) {
        bool pFlag = true;
        for(const auto& elem : pNum) {
            if(elem > sqrt(num)) break;
            if(num % elem == 0) {
                pFlag = false;
                break;
            }
        }
        if(pFlag) {
            pNum.push_back(num);
        }
    }

    // cout << pNum.size();

    // for(const auto& ele : pNum) {
    //     cout << ele << ' ';
    // }
    // cout << '\n';

    int lo = 0;
    int hi = 0;
    int sum = 0;
    int cnt = 0;
    int end = pNum.size();

    while(1) {
        if(sum >= N) sum -= pNum[lo++];
        else if(hi == end) break;   //  더 이상 더할꺼 없으면
        else sum += pNum[hi++];     // 더 이상 더해볼꺼 없을 때 까지..


        if(sum == N) cnt++;
    }

    cout << cnt;
    

    return 0;
}