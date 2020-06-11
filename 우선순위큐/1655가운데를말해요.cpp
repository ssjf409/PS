#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int N, input;
    scanf("%d", &N);
    /*
    vector<int> v;
    vector<int>::iterator iter;
    int len;

    for(int i = 0; i < N; i++) {
        scanf("%d", &input);
        iter = lower_bound(v.begin(), v.end(), input);
        v.insert(iter, input);
        len = v.size() - 1;
        printf("%d\n", v[len / 2]);
    }
    */

    priority_queue<int> maxHeap;
    priority_queue<int> minHeap;

    for(int i = 0; i < N; i++) {
        scanf("%d", &input);
        if(maxHeap.size() > minHeap.size()) minHeap.push(input);
        else maxHeap.push(input);
        if(!maxHeap.empty()&&!minHeap.empty()&&maxHeap.top()>minHeap.top()){
            int maxTop = maxHeap.top(), minTop = minHeap.top();
            maxHeap.pop(), minHeap.pop();
            maxHeap.push(minTop);
            minHeap.push(maxTop);
		}
        printf("%d\n", maxHeap.top());
    }

    return 0;
}