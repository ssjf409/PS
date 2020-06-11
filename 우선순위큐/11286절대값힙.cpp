#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int main() {
    priority_queue<pair<int, int>> pq;
    int N, input;
    scanf("%d", &N);

    for(int i = 0; i < N; i++) {
        scanf("%d", &input);
        if(input == 0) {
            if(pq.empty()) {
                printf("0\n");
            } else {
                printf("%d\n", pq.top().first * pq.top().second);
                pq.pop();
            }
        } else {
            pq.push({input < 0 ? input : -input, input < 0 ? 1 : -1});
        }
    }

    return 0;
}