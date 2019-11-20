#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    return a % b ? gcd(b, a%b) : b;
}
 

int main() {
    int N;
    cin >> N;
    vector<int> v(N);

    for(int i = 0; i < N; i++) {
        cin >> v[i];
    }

    for(int i = 1; i < N; i++) {
        int k = gcd(v[0], v[i]);
 
        cout << v[0] / k << '/' << v[i] / k << '\n';
    }
    return 0;
}