#include <iostream>
#include <vector>
#define INF 987654321
#define PAPER_SIZE 10

using namespace std;

int cnt, result;
int paper[6] = {0, 5, 5, 5, 5, 5};



void cover(vector<vector<int>>& paper, int y, int x, int paperSize, int piece) {
    for(int i = y; i < y + paperSize; i++) {
        for(int j = x; j < x + paperSize; j++) {
            paper[i][j] = piece;
        }
    }
}
bool find(const vector<vector<int>>& paper, int y, int x, int paperSize) {
    for(int i = y; i < y + paperSize; i++) {
        for(int j = x; j < x + paperSize; j++) {
            if(paper[i][j] == 0) return false;
        }
    }
    return true;
}

bool isClear(const vector<vector<int>>& paper) {
    for(int i = 0; i < PAPER_SIZE; i++) {
        for(int j = 0; j < PAPER_SIZE; j++) {
            if(paper[i][j]) {
                return false;
            }
        }
    }
    return true;
}



void getPaperCnt(vector<vector<int>>& paper, int y, int x) {

    if(x == PAPER_SIZE) {
        getPaperCnt(paper, y + 1, 0);
        return;
    }

    if(y == PAPER_SIZE) {
        result = min(result, cnt);
        return;
    }

}


int main() {
    vector<vector<int>> paper(10, vector<int>(10));
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            cin >> paper[i][j];
        }
    }

    // getPaperCnt();
    
    if(result == INF) {
        cout << -1;
    } else {
        cout << result;
    }
    return 0;
}