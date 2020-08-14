#include <iostream>
#include <vector>

using namespace std;

vector<vector<long long>> cache;


long long getNumPinary(int& N, int index, bool isPreOne) {
    if(N == index) return 1;

    long long& ret = cache[index][isPreOne];
    if(ret != -1) return ret;

    ret = 0;

    ret += getNumPinary(N, index + 1, false);
    
    if(!isPreOne) {
        ret += getNumPinary(N, index + 1, true);
    }



    return ret;
}

int main() {
    int N;
    cin >> N;

    cache.assign(N, vector<long long>(2, -1));

    cout << getNumPinary(N, 1, true);
}