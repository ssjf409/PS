#include <iostream>
#include <vector>

using namespace std;


int main() {
    int t;
    cin >> t;

    for(int i = 0; i < t; i++) {
        int n;
        cin >> n;
        
        vector<int> arr(n);
        vector<int> visited(n, 0);

        for(int j = 0; j < n; j++) {
            arr[j] = j + 1;
        }
        
        for(int j = 0; j < n; j++) {
            visited[j] = true;
            if(getPerm(arr, visited, j)) break;
            visited[j] = false;
        }
        
    }

    return 0;
}