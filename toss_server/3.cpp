#include <iostream>
#include <unistd.h>

using namespace std;

int compute(int n);

int main() {
	// [!!주의!!] compute 함수는 이미 구현되어있지만, 숨김처리되어 있습니다. 호출해서 테스트 해주세요.
	char input[100];
	cin >> input;
	cout << "Hello Goorm! Your input is " << compute(1) << endl;
	return 0;
}