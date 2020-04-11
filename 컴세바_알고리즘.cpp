#include <iostream>

using namespace std;

int main() {
    // 테스트 케이스를 N에 받고 N번 반복.
    int N;
    cin >> N;
    for(int i = 0; i < N; i++) {
        
        // 각 테스트 케이스마다 주는 입력을 string으로 받음
        string str;
        cin >> str;

        // 각 테이스 마다 계산 결과를 출력할 sum과 O가 한번 들어올 때마다 늘려줄 cnt를 1로 설정
        int sum = 0;
        int cnt = 1;

        // 문자열 길이만큼 문자열의 한 문자씩 살펴보며, O 문자이면 sum에 cnt 누적, 아니면 cnt를 1로 초기화
        // for문 다 돌고 나면 문자열 다 살펴 봤으므로, 결과를 출력한다.
        for(int j = 0; j < str.size(); j++) {
            if(str[j] == 'O') {
                sum += cnt;
                cnt++;
            } else {
                cnt = 1;
            }
        }
        cout << sum << '\n';
    }
    return 0;
}