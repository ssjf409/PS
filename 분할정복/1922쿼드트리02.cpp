#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

vector<string> v_image;
vector<char> result;
queue<char> q;


bool compress(int a, int b, vector<string> v_image, int length) {
    char start_char = v_image[a][b];
    int half_length = length / 2;
    bool clear_flag = true;

    if(length == 1) {
        cout << start_char;
        return true;  
    }


    for(int i = 0; i < length && clear_flag; i++) {
        for(int j = 0; j < length; j++) {
            if(v_image[i+a][j+b] != start_char) {
                clear_flag = false;
                break;
            }
        }
    }
    
    if(clear_flag) {
        cout << start_char;
        return true;
    }
    cout << '(';
    compress(a, b, v_image, half_length);
    compress(a, b + half_length, v_image, half_length);
    compress(a + half_length, b, v_image, half_length);
    compress(a + half_length, b + half_length, v_image, half_length);
    cout << ')';



}

int main() {
    int N;
    cin >> N;

    
    for(int i = 0; i < N; i++) {
        string str;
        cin >> str;
        v_image.push_back(str);
    }
    compress(0, 0, v_image, v_image.size());

    return 0;
}