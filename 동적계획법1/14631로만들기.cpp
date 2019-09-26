#include <iostream>
#include <vector>

using namespace std;

int Count_common_divider(int N) {
    int cnt_2 = 0;
    int cnt_3 = 0;

    while((N % 2) == 0) {
        N /= 2;
        cnt_2++;    
    }
    while((N % 3) == 0) {
        N /= 3;
        cnt_3++;
    }
    return cnt_2 + cnt_3;
}


int main() {
    int N;
    cin >> N;
    
    // int com_div = Count_common_divider(N);
    // int min = com_div;
    // for(int i = 1; i <= com_div; i++) {
    //     if(Count_common_divider(N-i) + i < min) {
    //         min = Count_common_divider(N-i) + i;
    //     }
    // }
    
    cout << min;

    return 0;
}