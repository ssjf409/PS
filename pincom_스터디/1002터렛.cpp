#include <iostream>
#include <cmath>
using namespace std;

float Get_distance(int x1, int y1, int x2, int y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main() {
    int T;
    int x1,y1,r1,x2,y2,r2;
    cin >> T;

    for(int i = 0; i < T; i++) {
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

        float distance = Get_distance(x1, y1, x2, y2);

        if(r1 + r2 < distance) {
            cout << "0\n";
        } else if(r1 + r2 == distance) {
            cout << "1\n";
        } else {
            int longer = r1 > r2 ? r1 : r2;
            int shorter = r1 < r2 ? r1 : r2;
            int diff = longer - shorter;
            if(distance == 0 && r1 == r2) {
                cout << "-1\n";
            } else if(distance == longer) {
                cout << "2\n";
            } else if(distance + shorter == longer) {
                cout << "1\n";
            } else if(distance + shorter > longer) {
                cout << "2\n";
            } else if(distance + shorter < longer){
                cout << "0\n";
            } else {
                cout << "2\n";
            }
        }
    }
    return 0;
}