#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>

using namespace std;

void solution(int numOfOrder, string *orderArr) {
  // TODO: 이곳에 코드를 작성하세요. 추가로 필요한 함수와 전역변수를 선언해서 사용하셔도 됩니다.
    for(int caseTest = 0; caseTest < numOfOrder; caseTest++) {
        string str = orderArr[caseTest];
        string order = "";

        for(int i = 0; i < str.size(); i++) {
            if(str[i] != ')') {
                if(order.size() >= 1 && order.back() >= '1' && order.back() <= '9' && str[i] != '(') {
                    char c = order.back();
                    order.pop_back();
                    for(int j = 0; j < c - '0'; j++) {
                        order += str[i];
                    }
                } else {
                    order += str[i];
                }
                continue;
            }

            string temp = "";
            while(order.back() != '(') {
                temp.push_back(order.back());
                order.pop_back();
            }
            order.pop_back();

            reverse(temp.begin(), temp.end());

            char cmd = order.back();
            order.pop_back();


            if(cmd == 'R' || cmd == 'G' || cmd == 'B') {
                for(int i = 0; i < temp.size(); i++) {
                    order += cmd;
                    order += temp[i];
                }
            } else {
                for(int i = 0; i < cmd - '0'; i++) {
                    order += temp;
                }
            }

        }

        cout << order << endl;

    }
}

struct input_data {
  int numOfOrder;
  string *orderArr;
};

void process_stdin(struct input_data& inputData) {
  string line;
  istringstream iss;

  getline(cin, line);
  iss.str(line);
  iss >> inputData.numOfOrder;

  inputData.orderArr = new string[inputData.numOfOrder];
  for (int i = 0; i < inputData.numOfOrder; i++) {
    getline(cin, line);
    iss.clear();
    iss.str(line);
    iss >> inputData.orderArr[i];
  }
}

int main() {
  struct input_data inputData;
  process_stdin(inputData);

  solution(inputData.numOfOrder, inputData.orderArr);
  return 0;
}