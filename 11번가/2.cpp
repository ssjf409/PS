#include <vector>
#include <unordered_map>

vector<int> solution(vector<string> &S) {
    vector<int> ret;
    int N = S.size();
    int M = S[0].size();

    // hash_map
    unordered_map<char, int> m;
    for(int j = 0; j < M; j++) {
        m.clear();
        for(int i = 0; i < N; i++) {
            char cur = S[i][j];
            
            // cur is not used yet
            if(m.find(cur) == m.end()) {
                m[cur] = i;
            } else { // cur has been used
                ret = {m[cur], i, j};
                return ret;
            }
        }
    }
    return ret;
}
