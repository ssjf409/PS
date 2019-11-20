#include <iostream>

using namespace std;

int main() {
    int first, second;
    cin >> first >> second;

    if(first > second) {
    } else if(second > first) {
        int temp = first;
        first = second;
        second = temp;
    } else {
        cout << first << '\n';
        cout << first << '\n';
        return 0;
    }

    
    for(int i = second; i > 0; i--) {
        if(first % i == 0 && second % i == 0) {
            cout << i << '\n'; // 최대 공약수
            break;
        }
    }

    for(long long int i = first; i <= first * second; i++) {
        if(i % first == 0 && i % second == 0) {
            cout << i << '\n'; // 최소 공배수
            break;
        }
    }
    


    return 0;
}