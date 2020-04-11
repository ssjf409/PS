#include <iostream>
#define MAX 8

using namespace std;

int N, M;
int arr[MAX + 1];

void printSeq(int layer) {
    if(layer == M) {
        for(int i = 0; i < M; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }
    
    for(int num = layer == 0 ? 1 : arr[layer - 1]; num <= N; num++) {
        arr[layer] = num;
        printSeq(layer + 1);
    }
}


int main() {
    cin >> N >> M;
    
    printSeq(0);
    return 0;
}