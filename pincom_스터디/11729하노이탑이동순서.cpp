#include <iostream>
#include <vector>

using namespace std;

vector<pair<char, char>> v;
int cnt = 0;

void move(int n, char from, char to) {
    cnt++;
    v.push_back(make_pair(from, to));//
}

void hanoi(int n, char from, char temp, char to) {
    if(n == 1) {
        move(n, from, to);
    } else {
        hanoi(n - 1, from, to, temp);
        move(n, from, to);
        hanoi(n - 1, temp, from, to);
    }
}

int main() {
    int N;
    cin >> N;
    hanoi(N, '1', '2', '3');

    cout << cnt << '\n';
    for(int i = 0; i < v.size(); i++) {
        cout << v[i].first << ' ' << v[i].second << '\n';
    }

    return 0;
}