#include <iostream>
#include <limits>
#include <vector>

using namespace std;


int maxValue = numeric_limits<int>::min();
int minValue = numeric_limits<int>::max();

int N;
vector<int> equVar;

int operNum[4];

void getMinMax(int res, int layer) {
    if(layer == N) {
        if(res > maxValue) maxValue = res;
        if(res < minValue) minValue = res;
        return;
    }
    if(layer == 0) {
        getMinMax(equVar[0], layer + 1);
    }

    for(int oper = 0; oper < 4; oper++) {
        if(operNum[oper] == 0) continue;
        operNum[oper]--;
        switch(oper) {
            case 0:
                getMinMax(res + equVar[layer], layer + 1);
            break;

            case 1:
                getMinMax(res - equVar[layer], layer + 1);
            break;

            case 2:
                getMinMax(res * equVar[layer], layer + 1);
            break;

            case 3:
                getMinMax(res / equVar[layer], layer + 1);
            break;
        }
        operNum[oper]++;
    }
}


int main() {
    cin >> N;
    equVar.assign(N, 0);
    for(int i = 0; i < N; i++) {
        cin >> equVar[i];
    }
    for(int i = 0; i < 4; i++) {
        cin >> operNum[i];
    }

    getMinMax(0, 0);
    cout << maxValue << '\n';
    cout << minValue << '\n';
    return 0;
}