#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;



void match(vector<pair<string, string>>& songNsingers, string songs, string singers) {
    
    string str1 = songs.substr(0, songs.size() -2);
    string str2 = singers.substr(0, singers.size() - 2);
    int index_str1, index_str2;
    while(true) {
        index_str1 = str1.find('\t');
        index_str2 = str2.find('\t');
        if(index_str1 == -1) {
            songNsingers.push_back(make_pair(str1.substr(0, str1.size()), str2.substr(0, str2.size())));    
            break;
        }


        songNsingers.push_back(make_pair(str1.substr(0, index_str1), str2.substr(0, index_str2)));
        str1 = str1.substr(index_str1 + 2);
        str2 = str2.substr(index_str2 + 2);
    }
}

bool compare(pair<string, string> p1, pair<string, string> p2) {
    return p1.second < p2.second;
}

bool compare2(pair<string, double> p1, pair<string, double> p2) {
    return p1.second < p2.second;
}



int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int testCase;
    cin >> testCase;
    cin.ignore(256,'\n');
    for(int i_testCase = 0; i_testCase < testCase; i_testCase++) {

        vector<pair<string, string>> songNsingers;

        string str;
        string str2;
        
        getline(cin, str);
        getline(cin, str2);
        // cout << str << '\n';
        // cout << str2 << '\n';
        
        
        match(songNsingers, str, str2);

        sort(songNsingers.begin(), songNsingers.end(), compare);
        vector<pair<string, int>> songCnt;
        for(int i = 0; i < songNsingers.size(); i++) {
            bool flag = false;
            for(int j = 0; j < songCnt.size(); j++) {
                if(songNsingers[i].second == songCnt[j].first) {
                    songCnt[j].second++;
                    flag = true;
                    break;
                }
            }
            if(flag == false) {
                songCnt.push_back(make_pair(songNsingers[i].second, 1));
            }
        }

        int sum = 0;
        for(int i = 0; i < songCnt.size(); i++) {
            sum += songCnt[i].second;
        }

        vector<double> songOrder;
        srand((unsigned int)time(NULL));
        for(int i = 0; i < songCnt.size(); i++) {
            double term = (double)songCnt[i].second;
            double first = ((rand() / (float)RAND_MAX) * term) / term;
            for(int j = 0; j < songCnt[i].second; j++) {
                songOrder.push_back(first + j * term);
            }
        }

        vector<pair<string, double>> songOrder2;
        for(int i = 0; i < songNsingers.size(); i++) {
            songOrder2.push_back(make_pair(songNsingers[i].first, songOrder[i]));
        }
        sort(songOrder2.begin(), songOrder2.end(), compare2);

        for(int i = 0; i < songOrder2.size() - 1; i++) {
            cout << songOrder2[i].first << '\t';
        }
        cout << songOrder2[songOrder2.size() - 1].first << '\n';
        
        // for(int i = 0; i < songOrder2.size(); i++) {
        //     cout << songOrder2[i].first << " " << songOrder2[i].second << '\n';
        // }
    }


    return 0;
}