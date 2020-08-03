#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	string str, temp;
	getline(cin, str);

	vector<int> kim2lee;
    vector<int> lee2kim;

	int index;
	while(str != "") {
		index = str.find(" ");
		temp = str.substr(index + 1);
		kim2lee.push_back(stoi(str.substr(0, index)));
		if(index == -1) break;
		str = temp;
	}

    getline(cin, str);
	while(str != "") {
		index = str.find(" ");
		temp = str.substr(index + 1);
		lee2kim.push_back(stoi(str.substr(0, index)));
		if(index == -1) break;
		str = temp;
	}

    int previous = 0;
    for(int i = 0; i < kim2lee.size(); i++) {
        int temp = kim2lee[i] - lee2kim[i] - previous;
        if(temp < 0) {
            previous = -temp;
            cout << 0 << ' ';
        } else {
            previous = 0;
            cout << temp << ' ';
        }
    }
    


	return 0;
}