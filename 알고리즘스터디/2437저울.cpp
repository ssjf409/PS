#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> arr(N);

    
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    int num = 0;
    
    for(int i = 0; i < arr.size(); i++) {
        if(num + 1 < arr[i]) break;
        else {
            num += arr[i];
        }
    }

    cout << num + 1;
    

    return 0;
}