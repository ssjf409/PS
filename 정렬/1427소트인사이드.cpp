#include <iostream>
#include <string>

using namespace std;

int main() {
    string str;
    cin >> str;
    int arr[10] = {0};

    for(int i = 0; i < str.size(); i++) {
        arr[str[i] - '0']++;
        //cout << arr[str[i] - '0'] << endl;
    }
    for(int i = 9; i >= 0; i--) {
        for(int j = 0; j < arr[i]; j++) {
            cout << i;
        }
    }
    // for(int i = sizeof(arr) / sizeof(arr[0]); i > 0; i++) {
    //     if(arr[i]) {
    //         cout << arr[i];
    //     }
    // }
    return 0;
}