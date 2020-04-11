#include <iostream>
#include <vector>

using namespace std;

int main() {
    int testCase;
    cin >> testCase;
    for(int i = 1; i <= testCase; i++) {
        int mapSize;
        cin >> mapSize;
        int map[mapSize][mapSize];

        vector<pair<int, int>> point;

        for(int j = 0; j < mapSize; j++) {
            for(int k = 0; k < mapSize; k++) {
                cin >> map[j][k];
                if(map[j][k]) point.push_back(make_pair(j, k));
            }
        }

        

    }
}