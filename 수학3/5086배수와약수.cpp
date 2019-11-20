#include <iostream>

using namespace std;

int main() {
    int first, second;

    while(true) {
        cin >> first >> second;
        if(first == 0 && second == 0) {
            break;
        }
        if(second % first == 0) {
            cout << "factor" << '\n';
        } else if(first % second == 0) {
            cout << "multiple" << '\n';
        } else {
            cout << "neither" << '\n';
        }
    }
    return 0;
}