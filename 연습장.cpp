#include <iostream>

using namespace std;

int main() {

    int arr[] = {1, 2, 3, 4, 5, 6, 7,};

    for(int element : arr) {
        element = 1;
    }

    for(const auto& element : arr) {
        cout << element << ' ';
    }

    return 0;
}