#include <iostream>
#include <vector>

using namespace std;
int main() {
    int N, M, D;
    cin >> N >> M >> D;

    vector<bool> goHospital(N, false);
    
    int input;
    for(int i = 0; i < M; i++) {
        cin >> input;
        goHospital[input] = true;
    }

    int cnt = 0;
    for(int i = 0; i < D; i++) {
        if(goHospital[i]) cnt++;
    }
    
    if(cnt >= D) {
        cout << -1;
        return 0;
    }

    for(int i = D; i < goHospital.size(); i++) {
        
    }


    
	return 0;
}