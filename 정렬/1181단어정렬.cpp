#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

bool compare(string str1, string str2) {
    if(str1.size() == str2.size()) {
        return str1 < str2;
    } else {
        return str1.size() < str2.size();
    }
}

int main() {
    int N;
    cin >> N;
    string str[N];
    for(int i = 0; i < N; i++) {
        cin >> str[i];
    }


    sort(str, str+N, compare);

    for(int i = 0; i < N; i++) {
        if(i > 0 && str[i-1] == str[i]){
            continue;
        }
        cout << str[i] << endl;
    }

    return 0;
}