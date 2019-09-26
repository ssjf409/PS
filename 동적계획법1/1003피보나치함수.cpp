#include <iostream>
#include <vector>


using namespace std;

vector<pair<int,int>> v;

int main() {
    int N;
    int fibo_index;
    cin >> N;

    v.push_back(make_pair(1, 0));
    v.push_back(make_pair(0, 1));

    for(int i = 2; i <= 40; i++) {
        v.push_back(make_pair(v[i-2].first + v[i-1].first, v[i-2].second + v[i-1].second));
    }

    for(int i = 0; i < N; i++) {
        cin >> fibo_index;
        cout << v[fibo_index].first << ' ' << v[fibo_index].second << '\n';
    }
    



    return 0;
}