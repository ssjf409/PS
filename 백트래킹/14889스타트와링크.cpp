#include <iostream>
#include <vector>
#include <limits>
#define MAX 20

using namespace std;

int minValue = numeric_limits<int>::max();

bool startTeam[MAX];

int table[MAX][MAX];
int cnt = 0;
// vector<int> sTeam;
int N;

void getMin(int layer) {
    
    if(layer == N) {
        if(cnt != N / 2) return;

        int startSum = 0, linkSum = 0;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(i == j) continue;
                if(startTeam[i] && startTeam[j]) startSum += table[i][j];
                if(!startTeam[i] && !startTeam[j]) linkSum += table[i][j];
            }
        }
        if(minValue > abs(startSum - linkSum)) minValue = abs(startSum - linkSum);
        return;
    }
    cnt++;
    startTeam[layer] = true;
    getMin(layer + 1);
    cnt--;
    startTeam[layer] = false;
    getMin(layer + 1);
}


int main() {
    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> table[i][j];
        }
    }
    getMin(1);
    cout << minValue;
    return 0;
}