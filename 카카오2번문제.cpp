/* Language - C++ */
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

void input(vector<vector<int>>& v, int a, int b) {
    for(int i = 0; i < a; i++) {
        for(int j = 0; j < b; j++) {
            cin >> v[i][j];
        }
    }
}

vector<vector<int>> copy(const vector<vector<int>>& v, int y, int x, int k) {
    vector<vector<int>> ret(k, vector<int>(k));
    for(int i = 0; i < k; i++) {
        for(int j = 0; j < k; j++) {
            ret[i][j] = v[y + i][x + j];
        }
    }

    return ret;
}

vector<long long> mulMatrix(const vector<vector<int>>& square, const vector<long long>& n) {
    int length = n.size();
    vector<long long> ret(length, 0);
    for(int i = 0; i < length; i++) {
        for(int j = 0; j < length; j++) {
            ret[i] += square[i][j] * n[j];
        }
    }
    return ret;
}

bool isEqual(const vector<vector<int>>& X, const vector<long long>& r_left, const vector<vector<int>>& Y, const vector<long long>& r) {
    int length = X.size();
    for(int i = 0; i < length; i++) {
        long long sum = 0;
        long long sum2 = 0;
        for(int j = 0; j < length; j++) {
            sum += X[i][j] * r_left[j];
            sum2 += Y[i][j] * r[j];
        }
        if(sum != sum2) return false;
    }
    return true;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int testCase;
    cin >> testCase;
    for(int i = 0; i < testCase; i++) {
        int n, m, k;
        double sum = 0.0;
        cin >> n >> m >> k;
        vector<vector<int>> X(k, vector<int>(k));
        vector<vector<int>> Y(k, vector<int>(k));
        vector<vector<int>> R(n, vector<int>(m));
        vector<vector<int>> temp(k, vector<int>(k));
        vector<long long> r(k);
        input(X, k, k);
        input(Y, k, k);
        input(R, n, m);


        for(int j = 0; j < n - k + 1; j++) {
            for(int l = 0; l < m - k + 1; l++) {
                
                temp = copy(R, j, l, k);
                srand((unsigned int)time(NULL));
                for(int s = 0; s < k; s++) {
                    r[s] = rand() % 1000000000;
                }
                vector<long long> r_left = mulMatrix(temp, r);


                if(isEqual(X, r_left, Y, r)) {
                    sum++;
                }
                

            }
        }
        cout << sum << '\n';
    }
    return 0;
}