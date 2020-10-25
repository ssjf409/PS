#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

void solution(int day, int width, int **blocks) {
  // TODO: 이곳에 코드를 작성하세요. 추가로 필요한 함수와 전역변수를 선언해서 사용하셔도 됩니다.
  
  vector<int> height(width, 0);

  int cnt = 0;

  for(int i = 0; i < day; i++) {
    int maxHeight = 0;
    for(int j = 0; j < width; j++) {
      height[j] += blocks[i][j];
      if(height[j] > maxHeight) {
        maxHeight = height[j];
      }
    }

    int curIndex = 0;
    int curHeight = height[0];

    int maxIndex = 0;
    int maxHeight = 0;

    for(int j = curIndex + 1; j < width; j++) {
      if(curHeight <= height[j]) {
        maxHeight = height[j];
        maxIndex = j;
      }
    }
    for(int j = curIndex + 1; j < maxIndex; j++) {
      cnt += curHeight - height[j];
      height[j] = curHeight;
    }
    curIndex = maxIndex;
    curHeight = maxHeight;


  }

}

struct input_data {
  int day;
  int width;
  int **blocks;
};

void process_stdin(struct input_data& inputData) {
  string line;
  istringstream iss;

  getline(cin, line);
  iss.str(line);
  iss >> inputData.day;

  getline(cin, line);
  iss.clear();
  iss.str(line);
  iss >> inputData.width;

  inputData.blocks = new int*[inputData.day];
  for (int i = 0; i < inputData.day; i++) {
    getline(cin, line);
    iss.clear();
    iss.str(line);
    inputData.blocks[i] = new int[inputData.width];
    for (int j = 0; j < inputData.width; j++) {
      iss >> inputData.blocks[i][j];
    }
  }
}

int main() {
	struct input_data inputData;
	process_stdin(inputData);

	solution(inputData.day, inputData.width, inputData.blocks);
	return 0;
}