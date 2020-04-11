/*#include <iostream>
#define MAX 8

using namespace std;

int N, M;
int arr[MAX + 1];
// bool visit[MAX + 1];

void printOrderSequence(int start, int layer) {
    if(layer == M) {
        for(int i = 0; i < M; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
    }
    
    for(int i = start; i <= N; i++) {
        arr[layer] = i;
        printOrderSequence(i + 1, layer + 1);
    }
}

int main() {
    cin >> N >> M;

    printOrderSequence(1, 0);
    return 0;
}*/

#include <iostream>
#define MAX 8

using namespace std;

int N, M;
int arr[MAX + 1];

void printOrderSequ(int layer) {
    if(layer == M) {
        for(int i = 0; i < M; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for(int num = layer == 0 ? 1 : arr[layer - 1] + 1; num <= N; num++) {
        arr[layer] = num;
        printOrderSequ(layer + 1);
    }
}

int main() {
    cin >> N >> M;
    
    printOrderSequ(0);

    return 0;
}