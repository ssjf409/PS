#include <iostream>
#include <string>

using namespace std;

int main() {
    string str;
    cin >> str;

    string chroatia[8] = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};

    for(int i = 0; i < 8; i++) {
        int index = 0;
        while(true)
        {
            index = str.find(chroatia[i], index);
            if(index == string::npos) break;
            str.replace(index, chroatia[i].length(), "A");
            index += 1; // 바꾼 길이 만큼 "A"만큼
        }
    }
    cout << str.size();
    

    return 0;
}