#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> temp_v;

bool Check(vector<pair<int, int>> v, pair<int, int> p) {
    for(int i = 0; i < v.size(); i++) {
        if(!(p.second <= v[i].first || p.first >= v[i].second)) {
            return false;
        }
    }
    return true;
}

int max_num = 0;

int Count_max(vector<pair<int, int>> v) {
    /*
    for(int i = 0; i < v.size(); i++) {
        if(Check(v, v[i])) {
            max_num++;
            temp_v.push_back(v[i]);
            int temp_max = Count_max(v);
            if(temp_max > max_num) {
                return temp_max;
            }
        }
    }
    return temp_v.size();
    */
}



int main() {
    int N;
    int first, second;
    cin >> N;

    vector<pair<int, int>> v;

    for(int i = 0; i < N; i++) {
        cin >> first >> second;
        v.push_back(make_pair(first, second));
    }
    int max = 0;

    
    int temp; //= Count_max(v, temp_v);

    if(temp > max) {
        max = temp;
    }
    

    cout << max;


}