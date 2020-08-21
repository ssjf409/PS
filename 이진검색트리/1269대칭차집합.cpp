#include <iostream>
#include <set>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    set<int> A, B;

    int input;
    for(int i = 0; i < a; i++) {
        cin >> input;
        A.insert(input);
    }

    
    for(int i = 0; i < b; i++) {
        cin >> input;
        B.insert(input);
    }

    int subtractA = 0, subtractB = 0;
    set<int>::iterator iter;

    for(iter = A.begin(); iter != A.end(); iter++) {
        if(B.find(*iter) == B.end()) {
            subtractA++;
        }
    }

    
    for(iter = B.begin(); iter != B.end(); iter++) {
        if(A.find(*iter) == A.end()) {
            subtractB++;
        }
    }

    cout << subtractA + subtractB;

    return 0;
}