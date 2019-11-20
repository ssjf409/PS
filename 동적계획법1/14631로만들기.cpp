#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> v(N+1);
    int temp_2;
    int temp_3;
    int temp_1;
    int min;
    v[1] = 0;

    for(int i = 2; i <= N; i++) {
        
        temp_1 = v[i-1] + 1;
        if(i % 3 == 0) {
            temp_3 = v[i/3] + 1;
            
            if(i % 2 == 0) {
                temp_2 = v[i/2] + 1;
                temp_3 > temp_2 ? (temp_2 > temp_1 ? min = temp_1: min = temp_2) : (temp_3 > temp_1 ? min = temp_1 : min = temp_3);
            } else {
                temp_3 > temp_1 ? min = temp_1 : min = temp_3;
            }


        } else if(i % 2 == 0) {
            temp_2 = v[i/2] + 1;
            temp_2 > temp_1 ? min = temp_1 : min = temp_2;
        } else {
            min = temp_1;
        }


        
        v[i] = min;
        cout << i << "번째 : " << min <<'\n';
    }

    cout << v[N];

    return 0;
}