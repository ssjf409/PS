#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
    string str, temp;
    cin >> str;
    
	vector<string> table;

	int index;
	while(str != "") {
		index = str.find(";");
		temp = str.substr(index + 1);
		table.push_back(str.substr(0, index));
		if(index == -1) break;
		str = temp;
	}

    for(int i = 0; i < table.size(); i ++) {
        cout << table[i] << endl;
    }


	return 0;
}