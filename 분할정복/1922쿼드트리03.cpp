#include <iostream>
#include <vector>
#include <string>

using namespace std;

string compress(vector<string>& image, int y, int x, int length) {
    char start = image[y][x];
    string str = "";
    if(length == 1) {
        return str + image[y][x];
    }
    bool clearFlag = true;
    for(int i = y; i < y + length; i++) {
        for(int j = x; j < x + length; j++) {
            if(image[i][j] != start) {
                clearFlag = false;
                break;
            }
        }
        if(!clearFlag) {
            break;
        }
    }
    if(clearFlag) {
        return str + image[y][x];
    }

    int half = length / 2;
    str += "(";
    str += compress(image, y, x, half);
    str += compress(image, y, x + half, half);
    str += compress(image, y + half, x, half);
    str += compress(image, y + half, x + half, half);
    str += ")";
    
    return str;
}

int main() {
    int N;
    cin >> N;
    vector<string> image;
    for(int i = 0; i < N; i++) {
        string str;
        cin >> str;
        image.push_back(str);
    }

    cout << compress(image, 0, 0, N);



    return 0;
}