#include <iostream>
#include <vector>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;


bool compare(const pair<string, pair<int, int>>& a, const pair<string, pair<int, int>>& b) {
    if(a.second.first == b.second.first) {
        a.second.second > b.second.second;
    }
    return a.second.first > b.second.first;
}

int main() {
	int N;
    cin >> N;

    map<string, int> winScore;
    map<string, int> setScore;
    map<string, int>::iterator winIter;
    map<string, int>::iterator setIter;
    


    for(int game = 0; game < N * (N - 1); game++) {
        string team1, team2;
        int point1, point2;
        cin >> team1 >> point1 >> team2 >> point2;
        if(winScore.find(team1) == winScore.end()) {winScore[team1] = 0; setScore[team1] = 0;}
        if(winScore.find(team2) == winScore.end()) {winScore[team2] = 0; setScore[team2] = 0;}

        if(point1 > point2) {
            winScore[team1]++;
        } else {
            winScore[team2]++;
        }
        
        setScore[team1] += point1 - point2;
        setScore[team2] += point2 - point1;
        // cout << team1 << " : " << setScore[team1] << endl;
        // cout << team2 << " : " << setScore[team2] << endl;
    }

    vector<pair<string, pair<int, int>>> score(N);

    winIter = winScore.begin();
    setIter = setScore.begin();
    for(int i = 0; winIter != winScore.end(); i++, winIter++, setIter++) {
        score[i].first = winIter->first;
        score[i].second.first = winIter->second;
        score[i].second.second = setIter->second;
    }


    sort(score.begin(), score.end(), compare);

    for(const auto& el : score) {
        cout << el.first << ' ' << el.second.first << ' ' << el.second.second << '\n';
    }
    


	return 0;
}