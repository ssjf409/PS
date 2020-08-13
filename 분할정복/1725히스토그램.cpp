#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> H;

int histogram(int start, int end) {
    if(start == end) return 0;
    if(start + 1 == end) return H[start];

    int mid = (start + end) / 2;
    int result = max(histogram(start, mid), histogram(mid, end));
    
    int width = 1, height = H[mid], left = mid, right = mid;

    while(right - left + 1 < end - start) {
        int p = start < left ? min(height, H[left - 1]) : -1;
        int q = right < end - 1 ? min(height, H[right + 1]) : -1;
        if(p >= q) {
            height = p;
            left--;
        } else {
            height = q;
            right++;
        }

        result = max(result, ++width * height);
    }

    return result;
}

int main() {
    cin >> N;
    H.resize(N);

    for(int i = 0; i < N; i++) {
        cin >> H[i];
    }

    cout << histogram(0, N);

    return 0;
}