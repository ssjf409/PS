#include <iostream>
#include <vector>
#define INF 987654321

using namespace std;

const int SWITCHES = 10, CLOCKS = 16;
const char linked[SWITCHES][CLOCKS+1] = {
    "xxx.............",
    "...x...x.x.x....",
    "....x.....x...xx",
    "x...xxxx........",
    "......"
};

bool areAligned(const vector<int>& clocks, int swtch);

void push(vector<int>& clocks, int swtch) {
    for(int clock = 0; clock < CLOCKS; clock++) {
        if(linked[swtch][clock] == 'x') {
            clocks[clock] += 3;
            if(clocks[clock] == 15) clocks[clock] = 3;
        }
    }
}

int solve(vector<int>& clocks, int swtch) {
    if(swtch == SWITCHES) areAligned ? 0 : INF;
    int ret = INF;
    for(int cnt = 0; cnt < 4; cnt++) {
        ret = min(ret, cnt + solve(clocks, swtch + 1));
        push(clocks, swtch);
    }
    return ret;
}

int main() {
    return 0;
}