#include <iostream>
#include <string>
//#include <cstdlib>
//#include <typeinfo>

using namespace std;



int makehap(int i) {
    string str = to_string(i);
    int sum = 0;
    for(int i = 0; i < str.size(); i++) {
        //cout << str[i] << typeid(str[i]).name()<< endl;

        sum += str[i] - '0';
    }
    //cout <<"sum : "<< sum << endl;

    return i + sum;

}


int main() {
    int N;
    cin >> N;
    int i;
    for(i = 1; i <= N; i++) {
        if(makehap(i) == N) {
            break;
        }
    }
    
    if(i <= N) {
        cout << i;
    } else {
        cout << 0;
    }




    return 0;
}