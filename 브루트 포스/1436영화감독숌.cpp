#include <iostream>
#include <string>

using namespace std;

int cnt = 0;

int make666Number(int N) {
    int number = 665;
    while(1) {
        number++;
        string str = to_string(number);
        if(str.find("666") != -1) {
            cnt++;
            if(cnt == N) {
                cout << number << endl;
                return -1;
                //return stoi(str.insert(str.find("666"), "666"));
            }
        }
    }

}

int main() {
    int N;
    cin >> N;

    make666Number(N);
    //cout << make666Number(N);

    return 0;
}