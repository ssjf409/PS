#include <iostream>
#include <algorithm>
#include <string> 

using namespace std;

int main() {
    string str = "Hello World!";
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    cout << str;
    return 0;
}