#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int n;
int ans;

int main() {
    cin >> n;
    int x;
    vector<int> vt;

    vt.push_back(numeric_limits<int>::min());
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        if (vt.back() < x) {
            vt.push_back(x);
            ans++;
        }
        else {
            auto it = lower_bound(vt.begin(), vt.end(), x);
            *it = x;
        }
    }
    cout << vt.size() - 1;

    return 0;
}