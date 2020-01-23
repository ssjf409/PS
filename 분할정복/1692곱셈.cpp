#include <iostream>

using namespace std;

int main() {
    long long A, B, C;
    cin >> A >> B >> C;

    A = A % C;
    

    while(B-- > 0) {
        A = (A * A) % C;
    }

    cout << A % C;
    return 0;
}