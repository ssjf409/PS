#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;


map<string, string> comp_want;
map<string, int> comp_cnt;
map<string, queue<char>> app_want;
// map<string, int> app_cnt;

vector<string> stov(string str) {
    int prev = -1;
    int cur = 0;
    vector<string> v;
    while(true) {
        prev = cur;
        cur = str.find(' ', prev);
        v.push_back(str.substr(prev, cur - prev));
        if(cur == -1) break;
        cur++;
    }
    return v;
}


vector<string> solution(vector<string> companies, vector<string> applicants) {
    vector<string> answer;
    
    for(int i = 0; i < companies.size(); i++) {
        vector<string> data = stov(companies[i]);
        comp_want[data[0]] = data[1];
        comp_cnt[data[0]] = stoi(data[2]);
    }
    
    
    for(int i = 0; i < applicants.size(); i++) {
        vector<string> data = stov(applicants[i]);
        
        queue<char> q;
        for(int j = 0; j < stoi(data[2]); j++) {
            q.push(data[1][j]);
        }
        
        app_want[data[0]] = q;
    }
    
    
    
    map<string, int>::iterator compIter;
    map<string, queue<char>>::iterator iter;
    
    while(true) {
        
        // for(compIter = comp)
        
        for(iter = app_want.begin(); iter != app_want.end(); iter++) {
            string name = iter->first;
            char wantComp = '.';
            if(!(iter->second).empty()) {
                wantComp = (iter->second).front();
                (iter->second).pop();
            }
            if(wantComp != '.') {
                
            }
        }
        
        
    }
    
    
    
    
    return answer;
}