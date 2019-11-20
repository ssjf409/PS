#include <iostream>

using namespace std;

struct cnt_nums {
    int cnt_2 = 0;
    int cnt_3 = 0;
    int cnt_5 = 0;
    int cnt_7 = 0;
}

cut_nums Count_0(int N) {
    

    int cnt_2 = 0;
    int cnt_3 = 0;
    int cnt_5 = 0;
    int cnt_7 = 0;
    if(N == 0 || N == 1) {
        cout << 0;
        return 0;
    }

    for(int i = 2; i <= N; i++) {
        int k = i;
        int k2 = i;
        while(k % 2 == 0) {
            k /= 2;
            cnt_2++;
        }
        while(k2 % 5 == 0) {
            k2 /= 5;
            cnt_5++;
        }
    }

    if(cnt_2 > cnt_5) {
        return cnt_5;
    } else {
        return cnt_2;
    }
    return -1;
}

int main() {

    return 0;
}