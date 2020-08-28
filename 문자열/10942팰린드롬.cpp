#include <iostream>
#include <vector>

using namespace std;

vector<int> seq;
vector<vector<int>> cache;

bool isPalindrome(int a, int b) {
    if(a == b) return true;
    if(a + 1 == b) return seq[a] == seq[b];

    int& ret = cache[a][b];
    if(ret != -1) return ret;

    ret = isPalindrome(a + 1, b - 1) && seq[a] == seq[b];

    return ret;
}

int main() {
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M;
    cin >> N;

    cache.assign(N, vector<int>(N, -1));

    seq.resize(N);
    for(int i = 0; i < N; i++) {
        cin >> seq[i];
    }
    
    cin >> M;
    int a, b;
    while(M--) {
        cin >> a >> b;
        cout << isPalindrome(a - 1, b - 1) << '\n';
    }


    return 0;
}