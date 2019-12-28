#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> v_image;
vector<char> result;

char check_clean(int str_y, int str_x, int end_y, int end_x) {
    char str_color = v_image[str_y][str_x];
    for(int i = str_y; i < end_y; i++) {
        for(int j = str_x; j < end_x; j++) {
            if(v_image[i][j] != str_color) {
                return false;
            }
        }
    }
    return str_color;
}


void compress(int str_y, int str_x, int end_y, int end_x) {
    result.push_back('(');
    
    int width = (end_y - str_y) / 2;
    char color; 


    if(color = check_clean(str_y, str_x, str_y + width, str_x + width)) {
        result.push_back(color);
    } else {
        compress(str_y, str_x, str_y + width, str_x + width);
    }
    
    if(color = check_clean(str_y, str_x + width, str_y + width, end_x)) {
        result.push_back(color);
    } else {
        compress(str_y, str_x + width, str_y + width, str_x);
    }

    if(color = check_clean(str_y + width, str_x, end_y, str_x + width)) {
        result.push_back(color);
    } else {
        compress(str_y + width, str_x, end_y, str_x + width);
    }
    
    if(color = check_clean(str_y + width, str_x + width, end_y, end_x)) {
        result.push_back(color);
    } else {
        compress(str_y + width, str_x + width, end_y, end_x);
    }


    result.push_back(')');
}

int main() {
    int N;
    cin >> N;


    for(int i = 0; i < N; i++) {
        string str;
        cin >> str;
        v_image.push_back(str);
    }
    
    char str_color = v_image[0][0];
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(str_color != v_image[i][j]) {
                compress(0, 0, N, N);

                for(int i = 0; i < result.size(); i++) {
                    cout << result[i];
                }
                return 0;
            }
        }
    }

    cout << str_color ;
    return 0;

    // compress(0, 0, N, N);

    // for(int i = 0; i < result.size(); i++) {
    //     cout << result[i];
    // }
    // return 0;
}


/* test case

8
11110000
11110000
11110000
11100000
00000111
00001111
00001111
00001111


*/