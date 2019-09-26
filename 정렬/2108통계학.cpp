#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>

using namespace std;





int main() {
    int N;
    cin >> N;
    int arr[N];
    long long int sum = 0;

    int maxCnt = 0;
    int cnt = 0;
    int value = 0;
    int secondValue = 1;

    for(int i = 0; i < N; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    sort(arr, arr+N);
    
    for(int i = 0; i < N-1; i++) {
        if(arr[i] == arr[i+1]) {
            cnt++;
           if(cnt > maxCnt) {
                maxCnt = cnt;
                secondValue = value;
                value = arr[i];
                
            }
        } else {
            cnt = 0;
        } 
    }

    float average = (float)sum / (float)N;
    if (average >= 0)
    {
        cout << int(average + 0.5) << endl;
    } else {
        cout << int(average - 0.5) << endl;
    }
    
    cout << arr[N / 2] << endl;
    //
 
    if(N == 1) {
        cout << arr[0] << endl;

    } else {
        
        if(secondValue == value) {
            cout<< secondValue << endl;
        } else {
            cout << value << endl;
            
        }
    }

    cout << arr[N-1] - arr[0] ;


    return 0;
}