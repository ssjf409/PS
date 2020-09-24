#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#define INF 987654321

using namespace std;

int minDepth = INF;
int minDepthVal = -1;

int getCnt(string str, int depth) {
    if(str.size() == 1) {
        if(depth < minDepth) {
            minDepth = depth;
            minDepthVal = stoi(str);
        }
        return 0;
    }
    
    int ret = INF;
    for(int i = 1; i < str.size(); i++) {
        if(str[i] != '0') {
            int a = stoi(str.substr(0, i));
            int b = stoi(str.substr(i));
            ret = min(ret, getCnt(to_string(a + b), depth + 1) + 1);
        }
    }
    
    return ret;
}


vector<int> solution(int n) {
    vector<int> answer;
    
    
    answer.push_back(getCnt(to_string(n), 0));
    answer.push_back(minDepthVal);
    
    
    return answer;
}