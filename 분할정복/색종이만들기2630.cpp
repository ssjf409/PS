#include <iostream>
#include <vector>

#define WHITE '0'
#define BLUE '1'

using namespace std;

int cnt_white_paper = 0;
int cnt_blue_paper = 0;

bool check_clean_paper(vector<vector<char>> v_paper, int y, int x, int edge_length) {
    //check same
    bool flag = true;
    char corner_color = v_paper[y][x];
    for(int i = y; (i < edge_length + y) && (flag == true); i++) {
        for(int j = x; j < edge_length + x; j++) {
            if(v_paper[i][j] != corner_color) {
                flag = false;
                break;
            }
        }
    }
    if(flag) {
        return true;
    } else {
        return false;
    }
}

void countPaper(vector<vector<char>> v_paper, int a, int b, int edge_length) {
    int half_edge_length = edge_length / 2;
    

    if(check_clean_paper(v_paper, a + 0, b + 0, half_edge_length)) {
        if(v_paper[a + 0][b + 0] == WHITE) {
            cnt_white_paper++;
        } else {
            cnt_blue_paper++;
        }
    } else if(half_edge_length != 1) {
        countPaper(v_paper, a + 0, b + 0, half_edge_length);
    } else {
        if(v_paper[a + 0][b + 0] == WHITE) {
            cnt_white_paper++;
        } else {
            cnt_blue_paper++;
        }
    }
    
    if(check_clean_paper(v_paper, a + half_edge_length, b + 0, half_edge_length)) {
        if(v_paper[a + half_edge_length][b + 0] == WHITE) {
            cnt_white_paper++;
        } else {
            cnt_blue_paper++;
        }
    } else if(half_edge_length != 1) {
        countPaper(v_paper, a + half_edge_length, b + 0, half_edge_length);
    } else {
        if(v_paper[a + half_edge_length][b + 0] == WHITE) {
            cnt_white_paper++;
        } else {
            cnt_blue_paper++;
        }
    }

    if(check_clean_paper(v_paper, a + 0, b + half_edge_length, half_edge_length)) {
        if(v_paper[a + 0][b + half_edge_length] == WHITE) {
            cnt_white_paper++;
        } else {
            cnt_blue_paper++;
        }
    } else if(half_edge_length != 1) {
        countPaper(v_paper, a + 0, b + half_edge_length, half_edge_length);
    } else {
        if(v_paper[a + 0][b + half_edge_length] == WHITE) {
            cnt_white_paper++;
        } else {
            cnt_blue_paper++;
        }
    }

    if(check_clean_paper(v_paper, a + half_edge_length, b + half_edge_length, half_edge_length)) {
        if(v_paper[a + half_edge_length][b + half_edge_length] == WHITE) {
            cnt_white_paper++;
        } else {
            cnt_blue_paper++;
        }
    } else if(half_edge_length != 1) {
        countPaper(v_paper, a + half_edge_length, b + half_edge_length, half_edge_length);
    } else {
        if(v_paper[a + half_edge_length][b + half_edge_length] == WHITE) {
            cnt_white_paper++;
        } else {
            cnt_blue_paper++;
        }
    }
}

int main() {
    int N;
    cin >> N;
    
    vector<char> v_line;
    vector<vector<char>> v_paper;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            char temp;
            cin >> temp;
            v_line.push_back(temp);
        }
        v_paper.push_back(v_line);
        v_line.clear();
    }

    countPaper(v_paper, 0, 0, N);


    cout << cnt_white_paper << '\n' << cnt_blue_paper;


    return 0;
}