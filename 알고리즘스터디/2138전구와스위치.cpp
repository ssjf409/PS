#include <iostream>
#include <vector>
#define INF 987654321
using namespace std;


int main() {
    int N;
    char input;
    cin >> N;
    vector<int> curlight(N);
    vector<int> light(N);

    for(int i = 0; i < N; i++) {
        cin >> input;
        curlight[i] = input - '0';
    }

    for(int i = 0; i < N; i++) {
        cin >> input;
        light[i] = input - '0';
    }
    

    

    return 0;
}