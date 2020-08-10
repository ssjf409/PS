#include <iostream>
#include <vector>
#define INF 987654321

using namespace std;

int N;
vector<int> input;
vector<long long> sum;

int main() {
    cin >> N;
    input.resize(N);
    sum.resize(N);

    int min = INF;
    long long s = 0;
    for(int i = 0; i < N; i++) {
        cin >> input[i];
        s += input[i];
        sum[i] = s;
    }

    


    return 0;
}