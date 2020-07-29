#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<bool> plugedNum(K + 1, false);

    vector<int> useCycle(K);
    for(int i = 0; i < K; i++) {
        cin >> useCycle[i];
    }

    for(int i = 0; i < N; i++) {
        plugedNum[useCycle[i]] = true;
    }

    vector<bool> temp(K + 1, false);

    int changeCnt = 0;

    int cnt = 0;
    bool isFit = false;

    for(int i = N; i < K; i++) {
        int curDevice = useCycle[i];
        if(plugedNum[curDevice] || temp[curDevice]) continue;
        else {
            temp[curDevice] = true;
            cnt++;

            if(cnt % N == 0) {
                for(int j = 1; j <= K; j++) {
                    if(!plugedNum[j] && temp[j]) changeCnt++;
                }
                plugedNum = temp;
                temp.assign(K + 1, false);
                cnt = 0;
                if(i == K - 1) isFit = true;
            }
        }
    }

    if(!isFit) {
        for(int j = 1; j <= K; j++) {
            if(!plugedNum[j] && temp[j]) changeCnt++;
        }
        plugedNum = temp;
        temp.assign(K + 1, false);
    }

    cout << changeCnt;


    return 0;
}