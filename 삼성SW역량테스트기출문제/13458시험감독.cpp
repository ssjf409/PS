#include <iostream>
#include <vector>


using namespace std;

typedef long long ll;

int main() {
    ll N, sum = 0;
    cin >> N;
    vector<ll> arr(N);

    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    ll B, C;
    cin >> B >> C;
    for(int i = 0; i < N; i++) {
        sum++;
        arr[i] -= B;

        if(arr[i] > 0) {
            if(arr[i] % C == 0) {
                sum += arr[i] / C;
            } else {
                sum += arr[i] / C + 1;
            }
        }
    }

    cout << sum;

    return 0;
}