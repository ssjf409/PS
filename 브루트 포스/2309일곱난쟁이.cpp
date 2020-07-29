#include <iostream>
#include <vector>
#include <algorithm>
#define DWARF_NUM 9

using namespace std;

vector<int> dwarfs(DWARF_NUM);
vector<int> choosed;


bool search(int index, int sum) {
    if(index == DWARF_NUM) {
        if(choosed.size() == 7 && sum == 100) {
            sort(choosed.begin(), choosed.end());
            for(int i = 0; i < choosed.size(); i++) {
                cout << choosed[i] << '\n';
            }
            return true;
        }
        return false;
    }

    choosed.push_back(dwarfs[index]);
    if(search(index + 1, sum + dwarfs[index])) return true;
    choosed.pop_back();
    if(search(index + 1, sum)) return true;
    return false;
}


int main() {

    for(int i = 0; i < DWARF_NUM; i++) {
        cin >> dwarfs[i];
    }

    search(0, 0);

    return 0;
}