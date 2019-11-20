#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;

    int div_num = 2;
    while(N != 1) {
        if((N % div_num) == 0) {
            N /= div_num;
            cout << div_num << '\n';
        } else {
            div_num++;
        }
    }
    return 0;
}