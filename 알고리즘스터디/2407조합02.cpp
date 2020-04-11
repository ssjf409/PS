#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;


int main() {
    
    string str1;
    string str2;

    cin >> str1 >> str2;

    str1 = (str1 > str2) ? str1 : str2;
    int length = min(str1.size(), str2.size());
    
    for(int i = 1; i <= length; i++) {
        
    }

    return 0;
}