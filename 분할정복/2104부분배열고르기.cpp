#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int N;
vector<int> input;
vector<long long> sum;

long long getMax(int start, int end) {
    if(start == end) return 0;
    if(start + 1 == end) return (sum[start] - sum[start - 1]) * input[start];

    int mid = (start + end) / 2;
    long long result = max(getMax(start, mid), getMax(mid, end));

    int width = 1, height = input[mid], left = mid, right = mid;

    while(right - left + 1 < end - start) {
        int p = start < left ? min(height, input[left - 1]) : -1;
        int q = right < end - 1 ? min(height, input[right + 1]) : -1;

        if(p >= q) {
            height = p;
            left--;
        } else {
            height = q;
            right++;
        }

        result = max((long long)result, (sum[right] - sum[left - 1]) * height);
    }

    return result;
}

int main() {
    cin >> N;
    input.assign(N + 1, 0);
    sum.assign(N + 1, 0);

    long long s = 0;
    for(int i = 1; i <= N; i++) {
        cin >> input[i];
        s += input[i];
        sum[i] = s;
    }

    cout << getMax(1, N + 1);

    


    return 0;
}