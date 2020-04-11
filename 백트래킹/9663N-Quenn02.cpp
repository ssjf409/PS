#include <iostream>
#define MAX 15

using namespace std;

int N;
int sum = 0;
int row[MAX];

bool promising(int rowIndex) {
    for(int i = 0; i < rowIndex; i++) {
        if(row[rowIndex] == row[i] || abs(row[rowIndex] - row[i]) == rowIndex - i) return false;
    }
    return true;
}


void getCaseNum(int rowIndex) {
    if(rowIndex == N) {
        sum++;
        return;
    }

    for(int colIndex = 0; colIndex < N; colIndex++) {
        row[rowIndex] = colIndex;
        if(promising(rowIndex)) {
            getCaseNum(rowIndex + 1);
        }
    }
}

int main() {
    cin >> N;
    getCaseNum(0);
    cout << sum;
    return 0;
}