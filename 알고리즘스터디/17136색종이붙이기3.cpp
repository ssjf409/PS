#include <iostream>
#include <vector>
#define INF 987654321
#define PAPER_SIZE 10

using namespace std;

int cnt, result;
int paper[10][10];

int paperCnt[6] = {0, 5, 5, 5, 5, 5};

void getPaperCnt(int y, int x) {
    if(x == PAPER_SIZE) {
        getPaperCnt(y + 1, 0);
    }
    if(y == PAPER_SIZE) {
        result = min(result, cnt);
        return;
    }

    if(paper[y][x] == 0) {
        getPaperCnt(y, x + 1);
        return;
    }

    for(int cPaper = 5; cPaper >= 1; cPaper--) {
        if(cPaper + y > PAPER_SIZE || cPaper + x > PAPER_SIZE || paperCnt[cPaper] == 0) continue;
        
        bool flag = true;
        for(int i = y; i < y + cPaper; i++) {
            for(int j = x; j < x + cPaper; j++) {
                if(paper[i][j] == 0) {
                    flag = false;
                    break;
                }
            }
            if(!flag) break;
        }

        if(!flag) continue;



        for(int i = y; i < y + cPaper; i++) {
            for(int j = x; j < x + cPaper; j++) {
                paper[i][j] = 0;
            }
        }

        paperCnt[cPaper]--;
        cnt++;

        getPaperCnt(y, x + cPaper);
        
        for(int i = y; i < y + cPaper; i++) {
            for(int j = x; j < x + cPaper; j++) {
                paper[i][j] = 1;
            }
        }
        

        paperCnt[cPaper]++;
        cnt--;
    }
}

int main() {
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            cin >> paper[i][j];
        }
    }

    result = INF;
    getPaperCnt(0, 0);

    if(result == INF) {
        cout << -1;
    } else {
        cout << result;
    }

    return 0;
}