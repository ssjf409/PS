#include <iostream>

using namespace std;

int main() {
    string A, B;
    cin >> A >> B;
    long long sumA = 0, sumB = 0;
    for(int i = 0; i < A.size(); i++) {
        sumA += A[i] - '0';
    }
    for(int i = 0; i < B.size(); i++) {
        sumB += B[i] - '0';
    }

    cout << sumA * sumB;
    
    
    
    return 0;
}