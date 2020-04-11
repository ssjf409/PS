#include <iostream>
#include <vector>
#include <limits>
#include <cstring>
#define MAX 20

using namespace std;

int minValue = numeric_limits<int>::max();
int startTeam[MAX];
int table[MAX][MAX];
int N;

void getMin(int sSum, int lSum, int layer) {
    if(layer == N / 2) {
        if(minValue > abs(sSum - lSum)) minValue = abs(sSum - lSum);
        return;
    }


    for(int i = 0; i < N; i++) {
        if(startTeam[i] != -1) continue;
            
        int temps = 0;
        int templ = 0;

        for(int j = 0; j < N; j++) {
            if(startTeam[j] == 1) {
                temps += table[j][i] + table[i][j];
            }
        }
        startTeam[i] = 1;
        getMin(sSum + temps, lSum, layer + 1);
        startTeam[i] = -1;

        
        for(int j = 0; j < N; j++) {
            if(startTeam[j] == 0) {
                templ += table[j][i] + table[i][j];
            }
        }
        startTeam[i] = 0;
        getMin(sSum, lSum + templ, layer + 1);

        startTeam[i] = -1;


    }
}


int main() {
    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> table[i][j];
        }
    }

    memset(startTeam, -1, sizeof(startTeam));
    getMin(0, 0, 1);
    cout << minValue;
    return 0;
}