#include <iostream>
#include <vector>

using namespace std;

int main() {
    int T;
    int case_number;
    int max_case_number = 0;
    cin >> T;
    int arr[T];

    for(int i = 0; i < T; i++) {
        cin >> case_number;
        arr[i] = case_number;
        if(case_number > max_case_number) {
            max_case_number = case_number;
        }
    }


    vector<long long int> v(max_case_number);
    v[0] = 0;
    v[1] = 1;
    v[2] = 1;
    v[3] = 1;
    v[4] = 2;
    for(int i = 5; i <= max_case_number; i++) {
        v[i] = v[i-1] + v[i-5];
    }

    for(int i = 0; i < T; i++) {
        cout << v[arr[i]] << '\n';
    }

    

    return 0;
}