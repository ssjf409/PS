#include <iostream>
#include <vector>
#define MAX 1000

using namespace std;

int main() {
    int N, L;
    cin >> N >> L;
    vector<int> isLeak(MAX + 1, false);
    vector<bool> isCoverd(MAX + 1, false);

    int a;
    for(int i = 0; i < N; i++) {
        cin >> a;
        isLeak[a] = true;
    }


    int usedTape = 0;
    for(int i = 1; i <= MAX; i++) {
        if(!isLeak[i] || isCoverd[i]) continue;

        for(int j = 0; j < L; j++) {
            if(i + j > MAX) break;
            isCoverd[i + j] = true;
        }
        usedTape++;
    }

    cout << usedTape;

    return 0;
}