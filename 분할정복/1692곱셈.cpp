#include <iostream>

using namespace std;

long long mult(long long a, long long b, long long c) {
    if(b == 1) return a % c;
    if(b % 2 == 1) {
        return (mult(a, b / 2, c) * mult(a, b / 2 + 1, c)) % c;
    } else {
        return (mult(a, b / 2, c) * mult(a, b / 2, c)) % c;
    }
}

int main() {
    int A, B, C;
    cin >> A >> B >> C;

    long long result = mult(A, B, C);
    cout << result;
    return 0;
}