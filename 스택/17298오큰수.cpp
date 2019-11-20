#include <iostream>
#include <stack>
#include <vector>


using namespace std;

int main() {
    int N;
    int num;
    cin >> N;

    stack<int> s;
    stack<int> result;

    int beforeNum = -1;
    

    for(int i = 0; i < N; i++) {
        cin >> num;
        s.push(num);
    }

    for(int i = 0; i < N; i++) {

    }


    return 0;
}

/* 반례

5
2 4 1 5 9

6
2 1 2 1 7 8

6
2 1 1 1 7 8
*/