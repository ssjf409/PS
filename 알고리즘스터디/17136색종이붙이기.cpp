#include <iostream>
#include <vector>
#define INF 987654321
#define PAPER_SIZE 10

using namespace std;

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



int getPaperCnt(vector<vector<int>>& paper, int five, int four, int three, int two, int one, int start) {
    if(five > 5 || four > 5 || three > 5 || two > 5 || one > 5) return INF;
    bool flag = true;
    for(int i = 0; i < PAPER_SIZE; i++) {
        for(int j = 0; j < PAPER_SIZE; j++) {
            if(paper[i][j]) {
                flag = false;
                break;
            }
        }
        if(!flag) break;
    }
    if(flag) {
        return five + four + three + two + one;
    }

    // cout << "=======================\n";
    // for(int i = 0; i < PAPER_SIZE; i++) {
    //     for(int j = 0; j < PAPER_SIZE; j++) {
    //         cout << paper[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }


    int ret = INF;

    for(int pSize = start; pSize >=1; pSize--) {
        for(int i = 0; i < PAPER_SIZE - pSize + 1; i++) {
            for(int j = 0; j < PAPER_SIZE - pSize + 1; j++) {
                if(find(paper, i, j, pSize)) {
                    cover(paper, i, j, pSize, 0);
                    int get;
                    switch(pSize) {
                        case 5:
                        get = getPaperCnt(paper, five + 1, four, three, two, one, 5);
                        break;
                        case 4:
                        get = getPaperCnt(paper, five, four + 1, three, two, one, 4);
                        break;
                        case 3:
                        get = getPaperCnt(paper, five, four, three + 1, two, one, 3);
                        break;
                        case 2:
                        get = getPaperCnt(paper, five, four, three, two + 1, one, 2);
                        break;
                        case 1:
                        get = getPaperCnt(paper, five, four, three, two, one + 1, 1);
                        break;
                    }
                    if(get != INF) {
                        ret = min(ret, get);
                        return ret;
                    }
                    cover(paper, i, j, pSize, 1);
                }
            }
        }
    }

    
    return ret;

}


int main() {
    vector<vector<int>> paper(10, vector<int>(10));
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            cin >> paper[i][j];
        }
    }
    
    int result = getPaperCnt(paper, 0, 0, 0, 0, 0, 5);
    if(result == INF) {
        cout << -1;
    } else {
        cout << result;
    }
    return 0;
}