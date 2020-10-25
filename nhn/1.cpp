#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

bool isFastPlayer(char *namesOfQuickPlayers, int numOfQuickPlayers, char c) {
    for(int i = 0; i < numOfQuickPlayers; i++) {
        if(namesOfQuickPlayers[i] == c) return true;
    }
    return false;
}

void solution(int numOfAllPlayers, int numOfQuickPlayers, char *namesOfQuickPlayers, int numOfGames, int *numOfMovesPerGame) {
  // TODO: 이곳에 코드를 작성하세요. 추가로 필요한 함수와 전역변수를 선언해서 사용하셔도 됩니다.

    
    vector<int> cnt(numOfAllPlayers, 0);
    cnt[0]++;

    int seatingSize = numOfAllPlayers - 1;
    vector<char> seatingPlayer(seatingSize);


    for(int i = 0; i < numOfAllPlayers - 1; i++) {
        seatingPlayer[i] = 'B' + i;
    }

    char tagger = 'A';
    int curIndex = 0;
    for(int i = 0; i < numOfGames; i++) {
        int move = numOfMovesPerGame[i];
        if(move >= 0) {
            curIndex = (curIndex + move) % seatingSize;
        } else {
            curIndex = (curIndex + move + seatingSize) % seatingSize;
        }
        
        char c = seatingPlayer[curIndex];

        if(!isFastPlayer(namesOfQuickPlayers, numOfQuickPlayers, c)) {
            swap(tagger, seatingPlayer[curIndex]);
        }

        cnt[tagger - 'A']++;

    }

    for(int i = 0; i < seatingSize; i++) {
        char c = seatingPlayer[i];
        int taggerCnt = cnt[c - 'A'];
        cout << c << ' ' << taggerCnt << endl;
    }
    cout << tagger << ' ' << cnt[tagger - 'A'] << endl;

}

struct input_data {
  int numOfAllPlayers;
  int numOfQuickPlayers;
  char *namesOfQuickPlayers;
  int numOfGames;
  int *numOfMovesPerGame;
};

void process_stdin(struct input_data& inputData) {
  string line;
  istringstream iss;

  getline(cin, line);
  iss.str(line);
  iss >> inputData.numOfAllPlayers;

  getline(cin, line);
  iss.clear();
  iss.str(line);
  iss >> inputData.numOfQuickPlayers;

  getline(cin, line);
  iss.clear();
  iss.str(line);
  inputData.namesOfQuickPlayers = new char[inputData.numOfQuickPlayers];
  for (int i = 0; i < inputData.numOfQuickPlayers; i++) {
    iss >> inputData.namesOfQuickPlayers[i];
  }

  getline(cin, line);
  iss.clear();
  iss.str(line);
  iss >> inputData.numOfGames;

  getline(cin, line);
  iss.clear();
  iss.str(line);
  inputData.numOfMovesPerGame = new int[inputData.numOfGames];
  for (int i = 0; i < inputData.numOfGames; i++) {
    iss >> inputData.numOfMovesPerGame[i];
  }
}

int main() {
  struct input_data inputData;
  process_stdin(inputData);

  solution(inputData.numOfAllPlayers, inputData.numOfQuickPlayers, inputData.namesOfQuickPlayers, inputData.numOfGames, inputData.numOfMovesPerGame);
  return 0;
}