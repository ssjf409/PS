#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987654321

using namespace std;

int ret = -INF;

// 부호에 맞게 계산해주는 함수
int calc(int a, int b, char c) {
    switch(c) {
        case '+':
            return a + b;
        break;
        case '-':
            return a - b;
        break;
        case '*':
            return a * b;
        break;
    }
    return -INF;
}


// 재귀적으로 호출하면서 괄호를 묶어본다.
void getCnt(const vector<pair<int, bool>>& num, const vector<char>& oper) {

    // 연산 없이 숫자 1개짜리만 들어올 경우가 있다.
    // 그런 경우도 그냥 리턴하면 안되므로 if부분을 넣어주었다.
    if(num.size() == 1) {
        if(num[0].first > ret) ret = num[0].first;
        return;
    }
    

    // 연산자 숫자 만큼 순회하며 괄호를 묶어본다.
    for(int i = 0; i < oper.size(); i++) {

        //이전에 연산되어 만들어진 숫자들은 건너 뛴다.
        if(num[i].second) continue;
        if(num[i + 1].second) continue;

        // 시도를 하더라도 데이터는 보존해야 하므로 새로 만든다.
        // 괄호로 묶어서 계산하면 숫자 갯수가 2개에서 1개로 줄어 듦으로
        // iterator를 만든다.
        // ex) A + (B * C) - D 이 경우 B와 C가 연산되어 하나의 숫자가 된다.
        // A + (?) - D 이런식으로.. 그래서 한 자리를 지운다.
        vector<pair<int, bool>> tempNum = num;
        vector<char> tempOper = oper;
        vector<pair<int, bool>>::iterator numIter = tempNum.begin();
        vector<char>::iterator operIter = tempOper.begin();

        // 괄호쳐서 연산해보기, 그리고 연산했으면 true로 처리해서 다시는 괄호로 못 묶게 한다.
        tempNum[i + 1].first = calc(tempNum[i].first, tempNum[i + 1].first, tempOper[i]);
        tempNum[i + 1].second = true;
        
        // 괄호쳐서 만들어진 숫자는 하나이므로 괄호 안에 있던 숫자 두개 중 왼쪽에 있는 숫자를 지운다.
        numIter += i;
        operIter += i;
        tempNum.erase(numIter);
        tempOper.erase(operIter);

        // 괄호를 더 만들 수 있다고 하더라도, 더 안 만들어야 커지는 경우도 있다.
        int sum = tempNum[0].first;
        for(int i = 0; i < tempOper.size(); i++) {
            sum = calc(sum, tempNum[i + 1].first, tempOper[i]);
        }


        getCnt(tempNum, tempOper);
        
        if(sum > ret) ret = sum;

    }


}


int main() {

    int N;
    cin >> N;

    string str;
    cin >> str;

    vector<pair<int, bool>> num(str.size() / 2 + 1);
    vector<char> oper(str.size() / 2);
    int numIdx = 0;
    int operIdx = 0;
    for(int i = 0; i < str.size(); i++) {
        if(i % 2 == 1) {
            oper[operIdx++] = str[i];
        } else {
            num[numIdx].second = false;
            num[numIdx++].first = str[i] - '0';
        }
    }

    getCnt(num, oper);
    
    cout << ret;

    return 0;
}