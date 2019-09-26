/*
BBBBBBBBWBWBW
BBBBBBBBBWBWB
BBBBBBBBWBWBW
BBBBBBBBBWBWB
BBBBBBBBWBWBW
BBBBBBBBBWBWB
BBBBBBBBWBWBW
BBBBBBBBBWBWB
WWWWWWWWWWBWB
WWWWWWWWWWBWB
*/

#include <iostream>

using namespace std;
string str[50];

int CheckCnt(int row, int col) {
    int sample1Cnt = 0;
    int sample2Cnt = 0;
    string sample1[8] ={
        {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
        {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
        {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
        {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
        {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
        {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
        {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
        {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
    };
    string sample2[8] ={
        {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
        {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
        {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
        {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
        {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
        {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
        {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
        {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
    };

    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            if(sample1[i][j] != str[row + i][col + j]) {
                sample1Cnt++;
            }
            if(sample2[i][j] != str[row + i][col + j]) {
                sample2Cnt++;
            }
        }
    }
    

    if(sample1Cnt <= sample2Cnt) {
        return sample1Cnt;
    } else {
        return sample2Cnt;
    }
}


int main() {
    int N;
    int M;
    cin >> N;
    cin >> M;
    int repaint = 9999;

    for(int i = 0; i < N; i++) {
         cin >> str[i];
    }

    for(int i = 0; i < N-7; i++) {
        for(int j = 0; j < M-7; j++) {
            int temp;
            if((temp = CheckCnt(i, j)) < repaint) {
                repaint = temp;
            }
        }
    }

    cout << repaint;


    return 0;
}