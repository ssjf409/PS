#include <iostream>
#define MAX 7

using namespace std;

int N, M;
int arr[MAX + 1];

void printSequence(int layer) {
    if(layer == M) {
        for(int i = 0; i < M; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for(int num = 1; num <= N; num++) {
        arr[layer] = num;
        printSequence(layer + 1);
    }
}

int main() {
    cin >> N >> M;
    printSequence(0);
    return 0;
}