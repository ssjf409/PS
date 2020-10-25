#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(int N) {
    vector<int> answer;
    int n = 0;
    long long max = 0;
    for(int i = 9; i >= 2; i--) {
        int num = N;
        string str = "";
        while(num != 0) {
            str += to_string(num % i);
            num /= i;
        }
        reverse(str.begin(), str.end());

        long long val = 1;
        for(int j = 0; j < str.size(); j++) {
            if(str[i] != '0') {
                val *= (str[j] - '0');
            }
        }

        if(val > max) {
            max = val;
            n = i;
        }
    }
    answer.push_back(n);
    answer.push_back(max);

    return answer;
}

int main() {
    int a;
    cin >> a;
    vector<int> temp = solution(a);

    for(int i = 0; i < temp.size(); i++) {
        cout << temp[i] << ' ';
    }

    return 0;
}