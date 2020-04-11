#include <iostream>
#define MAX 8

using namespace std;

int N, M;
int arr[MAX + 1];
bool visit[MAX + 1];

void printSequence(int layer) {
    if(layer == M) {
        for(int i = 0; i < M; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i = 1; i <= N; i++) {
        if(visit[i]) continue;
        visit[i] = true;
        arr[layer] = i;
        printSequence(layer + 1);
        visit[i] = false;
    }
}

int main() {
    cin >> N >> M;

    printSequence(0);

    return 0;
}