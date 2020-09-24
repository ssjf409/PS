#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

long long solution(string block, int pos) {
    long long answer = 0;

    stack<pair<char, long long>> left;
    stack<pair<char, long long>> right;

    char cur = block[pos - 1];
    long long cStep = 1;
    long long cnt = 0;


    for(int i = 0; i < pos - 1; i++) {
        if(left.empty()) {
            left.push({block[i], 1});
        } else if(left.top().first == block[i]) {
            int temp = left.top().second + 1;
            left.pop();
            left.push({block[i], temp});
        } else {
            left.push({block[i], 1});
        }
    }

    for(int i = block.size() - 1; i >= pos; i--) {
        if(right.empty()) {
            right.push({block[i], 1});
        } else if(right.top().first == block[i]) {
            int temp = right.top().second + 1;
            right.pop();
            right.push({block[i], temp});
        } else {
            right.push({block[i], 1});
        }
    }


    while(true) {
        cnt += cStep;
        if(cur == '>') {
            if(right.empty()) {
                break;
            }
            if(!left.empty() && left.top().first == '<') {
                int temp = left.top().second + 1;
                left.pop();
                left.push({'<', temp});
            } else {
                left.push({'<', 1});
            }
            cur = right.top().first;
            cStep = right.top().second;
            right.pop();
        } else {
            if(left.empty()) {
                break;
            }
            if(!right.empty() && right.top().first == '>') {
                int temp = right.top().second + 1;
                right.pop();
                right.push({'>', temp});
            } else {
                right.push({'>', 1});
            }
            
            cur = left.top().first;
            cStep = left.top().second;
            left.pop();
        }
    }
    answer = cnt;


    return answer;
}

int main() {
    string block;
    int pos;
    cin >> block >> pos;
    cout << solution(block, pos);

    return 0;
}