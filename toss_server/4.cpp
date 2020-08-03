#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;
int main() {

	string str, temp;
	getline(cin, str);

	vector<string> paying;

	int index;
	while(str != "") {
		index = str.find(" ");
		temp = str.substr(index + 1);
		paying.push_back(str.substr(0, index));
		if(index == -1) break;
		str = temp;
	}
    
    vector<string> previous;
    vector<string> temp2;
    for(int i = 0; i < paying.size(); i++) {
        bool used = false;
        temp2.clear();
        string cur = paying[i];
        for(int j = 0; j < previous.size(); j++) {
            if(previous[j] == cur) {
                used = true;
            } else {
                temp2.push_back(previous[j]);
            }
        }
        
        if(used) {
            previous.push_back(cur);
        } else {
            if(previous.size() == 5) {
                previous.clear();
                for(int j = 1; j < temp2.size(); j++) {
                    previous.push_back(temp2[j]);
                }
                previous.push_back(cur);
            } else if(previous.size() < 5) {
                previous.push_back(cur);
            }
        }




        
    }

	return 0;
}