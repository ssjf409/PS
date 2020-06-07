#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
vector<bool> visited;


int main() {
    cin >> n >> m;

    visited.assign(n, false);

    sort(visited.begin(), visited.end());


    return 0;
}