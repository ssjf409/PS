#include <vector>
#include <iostream>
#include <algorithm>
#define INF 987654321

using namespace std;

vector<vector<int>> cache;

int getMax(const vector<int>& cards, int index, int num) {
    if(num == 0) return 0;
    if(index < 0) return INF;
    
    int& ret = cache[index][num];
    if(ret != -1) return ret;
    
    ret = INF;
    
    int div = num / cards[index];
    
    if(num == div * cards[index]) {
        ret = min(ret, div);
        return ret;
    }
    
    for(int i = 0; i <= div; i++) {
        ret = min(ret, getMax(cards, index - 1, num - i * cards[index]) + i);
    }
    return ret;
}


int solution(int num, vector<int> cards) {
    int answer = 0;
    
    cache.assign(cards.size(), vector<int>(10001, -1));
    
    int result = getMax(cards, cards.size() - 1, num);
    if(result >= INF) {
        answer = -1;
    } else {
        answer = result;
    }
    return answer;
}