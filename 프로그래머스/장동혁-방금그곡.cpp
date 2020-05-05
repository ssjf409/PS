// https://programmers.co.kr/learn/courses/30/lessons/17683
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Result {
    int pTime;
    int index;
    string title;
    Result(int a, int b, string c) : pTime(a), index(b), title(c) {}
};

bool compare(const Result& a, const Result& b) {
    if(a.pTime == b.pTime) {
        return a.index < b.index;
    }
    return a.pTime > b.pTime;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "";
    vector<Result> ret;
    
    // C# -> c, B# -> b, F# -> f, G# -> g, A# -> a으로 변환
    while(true) {
        int idx = m.find('#');
        if(idx == -1) break;
        string temp = "";
        temp += m[idx - 1] - 'A' + 'a';
        m.replace(idx - 1, 2, temp);
    }
    
    for(int i = 0; i < musicinfos.size(); i++) {
        // 곡정보 뽑아내기
        string str = musicinfos[i];
        int sTime = stoi(str.substr(0, 2)) * 60 + stoi(str.substr(3, 2));
        int eTime = stoi(str.substr(6, 2)) * 60 + stoi(str.substr(9, 2));
        int pTime = eTime - sTime;
        int commaIdx = str.find(',', 12);
        string title = str.substr(12, commaIdx - 12);
        string melody = str.substr(commaIdx + 1, str.size() - commaIdx);

        // C# -> c, B# -> b, F# -> f, G# -> g, A# -> a으로 변환
        while(true) {
            int idx = melody.find('#');
            if(idx == -1) break;
            string temp = "";
            temp += melody[idx - 1] - 'A' + 'a';
            melody.replace(idx - 1, 2, temp);
        }
        
        // 해당 곡이 재생된 시간동안 생성된 멜로디 만들기
        int melTime = melody.size();
        string fullMelody = "";
        int cnt = pTime / melTime;
        while(cnt-- != 0) {
            fullMelody += melody;
        }
        fullMelody += melody.substr(0, (pTime % melTime));
        
        
        // m과 전체 재생된 멜로디에서 일치하는 부분 있는지 찾고
        // 일치하는 부분 있다면 그 부분 저장
        int findIdx = 0;
        findIdx = fullMelody.find(m, findIdx);
        
        if(findIdx != -1) {
            ret.push_back({pTime, i, title});
        }
        
        
    }
    
    // 못 찾았는지 확인 후, 찾았으면 정렬하기
    if(ret.empty()) {
        answer = "(None)";
    } else {
        sort(ret.begin(), ret.end(), compare);
        
        answer = ret[0].title;
    }
    
    
    
    return answer;
}