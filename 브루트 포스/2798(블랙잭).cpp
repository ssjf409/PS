//2789

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    int M;
    int number;
    int sum = 0;

    cin >> N;
    cin >> M;
    vector<int> vec;

    for(int i = 0; i < N; i++) {
        cin >> number;
        vec.push_back(number);
    }

    for(int i = 0; i < N - 2; i++) {
       for(int j = i + 1; j < N - 1; j++) {
           for(int k = j + 1; k < N; k++) {
               int Temp = vec[i] + vec[j] + vec[k];
               if(Temp <= M && Temp > sum) {
                   sum = Temp; 
               }
           }
       }
    }

    cout << sum;

}