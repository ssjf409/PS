#include <iostream>
#include <cstring>
#include <vector>
#define MAX 1000

using namespace std;

int N;
int arr[MAX];
int cache[MAX + 1];
int choice[MAX + 1];

int lis(int start) {
    int& ret = cache[start + 1];
    if(ret != -1) return ret;
    ret = 1;
    int bestNext = -1;
    for(int next = start + 1; next < N; next++) {
        if(start == -1 || arr[start] < arr[next]) {
            int cand = lis(next) + 1;
            if(cand > ret) {
                ret = cand;
                bestNext = next;
            }
        }
    }
    choice[start + 1] = bestNext;

    return ret;
}

void reconstruct(int start, vector<int>& seq) {
    if(start != -1) seq.push_back(arr[start]);
    int next = choice[start + 1];
    if(next != -1) reconstruct(next, seq);
}

int main() {
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    memset(cache, -1, sizeof(cache));
    memset(choice, -1, sizeof(choice));

    cout << lis(-1) - 1 << '\n';
    vector<int> seq;
    reconstruct(-1, seq);

    for(const auto& element : seq) {
        cout << element << ' ';
    }
    return 0;
}