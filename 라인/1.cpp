#include <string>
#include <vector>


using namespace std;

int solution(vector<vector<int>> boxes) {
    int answer = 0;
    
    int n = boxes.size();
    
    vector<int> arr(1000001, 0);
    for(int i = 0; i < boxes.size(); i++) {
        arr[boxes[i][0]]++;
        arr[boxes[i][1]]++;
    }
    
    for(int i = 1; i <= 1000000; i++) {
        if(arr[i] >= 2) {
            n -= arr[i] / 2;
        }
    }
    answer = n;
    
    
    return answer;
}