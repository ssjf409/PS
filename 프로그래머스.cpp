#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for(int i = 0; i < commands.size(); i++) {
        vector<int> temp;
        for(int j = commands[i][0]; j < commands[i][1]; j++) {
            temp.push_back(array[j]);
        }
        answer.push_back(array[commands[i][2]]);
    }
    
    sort(answer.begin(), answer.end());
    return answer;
}
