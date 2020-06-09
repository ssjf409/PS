#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;

int arr[9];
vector<int> input;
vector<bool> visited;

void printAllPath(int index, int num) {
    if(num == M) {
        for(int i = 0; i < M; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }
    if(index == N) return;

    for(int i = 0; i < N; i++) {
        if(index == 0 || arr[index - 1] <= input[i]) {
            arr[index] = input[i];
            printAllPath(index + 1, num + 1);
        }
    }
}

bool compare(const int& a, const int& b) {
    return a < b;
}

int main() {
    cin >> N >> M;
    input.assign(N, 0);
    visited.assign(N, false);

    for(int i = 0; i < N; i++) {
        cin >> input[i];
    }

    sort(input.begin(), input.end(), compare);

    printAllPath(0, 0);



    return 0;
}