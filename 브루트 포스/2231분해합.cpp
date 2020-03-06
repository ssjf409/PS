#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    int sum = 0;
    int temp;
    for(int i = 1; i <= N; i++) {
        temp = i;
        sum = temp;
        while(true) {
            if(!temp) break;
            sum += temp % 10;
            temp /= 10;
        }
        if(sum == N) {
            cout << i;
            return 0;
        }
    }
    cout << 0;
    return 0;
}