#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
    vector<int> a;
    a.push_back(1);
    a.push_back(2);

    int& c = a[1];
    a[0] = c;
    a[1] = 3;
    cout << a[0] << ' '<< a[1];

}