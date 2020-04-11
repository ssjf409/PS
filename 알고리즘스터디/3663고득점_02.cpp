#include <iostream>
#include <string>

using namespace std;

bool visit[1000];

int getMin(int start, int falseCnt, int length) {
    if(falseCnt == 0) {
        return 0;
    }

    int leftIndex = start;
    int rightIndex = start;
    int leftCnt = 0;
    int rightCnt = 0;

        // cout << "=========\n";
    while(true) {
        leftCnt++;
        if(leftIndex == 0) {
            leftIndex = length - 1;
        } else {
            leftIndex--;
        }
        if(visit[leftIndex] == false) break;
    }

    
    while(true) {
        rightCnt++;
        if(rightIndex == length - 1) {
            rightIndex = 0;
        } else {
            rightIndex++;
        }
        if(visit[rightIndex] == false) break;
    }

    visit[leftIndex] = true;
    int leftValue = getMin(leftIndex, falseCnt - 1, length) + leftCnt;
    visit[leftIndex] = false;

    
    visit[rightIndex] = true;
    int rightValue = getMin(rightIndex, falseCnt - 1, length) + rightCnt;
    visit[rightIndex] = false;

    return min(leftValue, rightValue);


}


int main() {
    int testCase;
    cin >> testCase;

    for(int tCaseNum = 0; tCaseNum < testCase; tCaseNum++) {
        string str;
        cin >> str;
        // for(int i = 0; i < str.size(); i++) {
        //     cout << str[i] - 'A' << ' ';
        // }
        int length = str.size();
        int cnt = 0;
        int sum = 0;
        for(int i = 0; i < str.size(); i++) {
            if(str[i] == 'A') visit[i] = true;
            else {
                if(str[i] - 'A' > 13) {
                    sum += 26 - (str[i] - 'A');
                } else {
                    sum += str[i] - 'A';
                }
                cnt++;
                visit[i] = false;
            }
        }

        
        
        visit[0] = true;
        // cout << sum << '\n';
        cout << sum + getMin(0, cnt - 1, length) << '\n';

    }

    

    return 0;
}