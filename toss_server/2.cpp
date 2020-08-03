#include <iostream>
#include <unistd.h>
#include <map>

using namespace std;

int compute(int n);

int main() {
	// [!!주의!!] compute 함수는 이미 구현되어있지만, 숨김처리되어 있습니다. 호출해서 테스트 해주세요.
	
	string str, temp;
	getline(cin, str);
	map<int, int> m;

	vector<int> nums;

	int index;
	while(str != "") {
		index = str.find(" ");
		temp = str.substr(index + 1);
		nums.push_back(stoi(str.substr(0, index)));
		if(index == -1) break;
		str = temp;
	}
	
	for(int i = 0; i < nums.size(); i++) {
		if(m.find(nums[i]) == m.end()) {
			int newNum = compute(nums[i]);
			m.insert({nums[i], newNum});
			cout << newNum << ' ';
		} else {
			cout << m[nums[i]] << ' ';
		}
	}
	
	
	return 0;
}