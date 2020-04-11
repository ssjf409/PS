#include <iostream>
#include <cstdio>
#include <string>
#define BITSIZE 100000

using namespace std;

int main() {
    string str1, str2;
    cin >> str1 >> str2;
    for(int i = 0; i < BITSIZE; i++) {
        if(str1[i] == '1' && str2[i] == '1') printf("%d", 1);
        else printf("%d", 0);
    }
    cout << '\n';
    for(int i = 0; i < BITSIZE; i++) {
        if(str1[i] == '1' || str2[i] == '1') printf("%d", 1);
        else printf("%d", 0);
    }
    cout << '\n';
    for(int i = 0; i < BITSIZE; i++) {
        if(str1[i] != str2[i]) printf("%d", 1);
        else printf("%d", 0);
    }
    cout << '\n';
    for(int i = 0; i < BITSIZE; i++) {
        if(str1[i] == '0') printf("%d", 1);
        else printf("%d", 0);
    }
    cout << '\n';
    for(int i = 0; i < BITSIZE; i++) {
        if(str2[i] == '0') printf("%d", 1);
        else printf("%d", 0);
    }
    

    
    return 0;
}