#include <iostream>
#include <vector>
#include <cmath>

using namespace std;




int main() {
    long long N, K;
    cin >> N >> K;

    long long center = ceil(N / 2.0);

    

    long long a, b;
    vector<int> color;

    for(int i = 0; i < K; i++) {

        cin >> a >> b;

        long long aVal;
        long long bVal;

        if(N % 2 == 1) {
            aVal = abs(a-center);
            bVal = abs(b-center);
        } else {
            aVal = abs(int(a-center-0.5));
            bVal = abs(int(b-center-0.5));
        }


        long long max = (aVal > bVal) ? aVal : bVal;

        long long gap = center - max;

        int colorVal = gap % 3;

        if(colorVal == 0) { // 노랑
            color.push_back(3);
        } else if(colorVal == 1) { // 빨강
            color.push_back(1);
        } else if(colorVal == 2) { // 파랑
            color.push_back(2);
        }
    }

    for(const auto& el : color) {
        cout << el << '\n';
    }

    return 0;
}