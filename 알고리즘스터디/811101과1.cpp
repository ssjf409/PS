#include <iostream>
#include <vector>
#include <string>

using namespace std;

int T, N;
vector<vector<int>> cache;


string getNum(string val, int depth) {
    if(depth > 100) {
        return ".";
    }
    if(stoi(val) % N == 0) {
        return "";
    }

    string zero = getNum(to_string(stoi(val) % N) + "0", depth + 1);
    string one = getNum(to_string(stoi(val) % N) + "1", depth + 1);

    if(zero == "") {
        zero
    }

    return 
}

int main() {
    cin >> T;
    while(T--) {
        cin >> N;
        cache.assign(N + 1, vector<int>(N + 1, -1));

        cout << getNum("1", 1);
    }



    return 0;
}