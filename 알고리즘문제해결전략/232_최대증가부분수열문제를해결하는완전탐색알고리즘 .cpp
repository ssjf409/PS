#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int lis(const vector<int>& A) {
    // 기저 사례 : A가 텅 비어 있을 때
    if(A.empty()) return 0;
    int ret = 0;
    for(int i = 0; i < A.size(); ++i) {
        vector<int> B;
        for(int j = i + 1; j < A.size(); j++) {
            if(A[i] < A[j]) {
                B.push_back(A[j]);
            }
        }
        ret = max(ret, 1 + lis(B));
    }
    return ret;
}

int main() {
    return 0;
}