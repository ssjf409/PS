#include <iostream>

using namespace std;

int main() {
    int A, B, V;
    cin >> A >> B >> V;

    int speed = A - B;

    int temp = (V - A) / speed;
    if((V - A) % speed == 0) {
        cout << temp + 1;
    } else {
        cout << temp + 2;
    }

    return 0;
}