#include <string>
#include <vector>
#include <deque>

using namespace std;

vector<int> solution(vector<int> ball, vector<int> order) {
    vector<int> answer;
    
    deque<int> dq;
    
    for(int i = 0; i < ball.size(); i++) {
        dq.push_back(ball[i]);
    }
    
    vector<bool> isReserved(1000001, false);
    
    for(int i = 0; i < order.size(); i++) {
        int target = order[i];
        if(dq.front() == target) {
            answer.push_back(target);
            dq.pop_front();
            
            while(!dq.empty() && isReserved[dq.front()]) {
                answer.push_back(dq.front());
                isReserved[dq.front()] = false;
                dq.pop_front();
            }
            
        } else if(dq.back() == target) {
            answer.push_back(target);
            dq.pop_back();
            
            while(!dq.empty() && isReserved[dq.back()]) {
                answer.push_back(dq.back());
                isReserved[dq.back()] = false;
                dq.pop_back();
            }
            
        } else {
            isReserved[target] = true;
        }
    }
    
    
    
    return answer;
}