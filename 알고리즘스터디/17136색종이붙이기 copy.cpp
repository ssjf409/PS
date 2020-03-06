#include <iostream>
#include <vector>
#define INF 987654321
#define PAPER_SIZE 10

using namespace std;


int paper[10][10];

int size[8] = {10, 8, 6, 5, 4, 3, 2, 1};

bool find(int y, int x, int length) {
    if(y + length > PAPER_SIZE || x + length > PAPER_SIZE) return false;
    for(int i = y; i < y + length; i++) {
        for(int j = x; j < x + length; j++) {
            if(!paper[i][j]) return false;
        }
    }
    return true;
}

int main() {
    for(int i = 0; i < PAPER_SIZE; i++) {
        for(int j = 0; j < PAPER_SIZE; j++) {
            cin >> paper[i][j];
        }
    }

    for(int i = 0; i < PAPER_SIZE; i++) {
        for(int j = 0; j < PAPER_SIZE; j++) {
            for(int k = 0; k < 8; k++) {
                if()
            }

        }
    }
    
    return 0;
}