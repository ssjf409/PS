#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void input(vector<int>& input) {
    for(int i = 0; i < 4; i++) {
        cin >> input[i];
    }
    sort(input.begin(), input.end());
}


int main() {
    int arr[13] = {0,};
    vector<int> temp(4);
    vector<int> temp2(4);
    char oper;
    bool isTry = false;
    bool realCoin[13] = {false,};
    bool contradiction = false;

    vector<vector<int>> data;
    vector<char> data_type;

    for(int testCase = 0; testCase < 3; testCase++) {


        bool being = false;
        input(temp);
        
        
        cin >> oper;
        if(oper == '>') {
            isTry = true;
            for(int i = 0; i < 4; i++) {
                arr[temp[i]]++;
            }
        } else if(oper == '<') {
            isTry = true;
            for(int i = 0; i < 4; i++) {
                arr[temp[i]]--;
            }
        } else {
            for(int i = 0; i < 4; i++) {
                realCoin[temp[i]] = true;
            }
        }



        for(int i = 0; i < data.size(); i++) {
            if(data[i] == temp) {
                being = true;
                switch(oper) {
                    case '>':
                    if(data_type[i] != 1) {
                        contradiction = true;
                    }
                    break;
                    case '<':
                    if(data_type[i] != -1) {
                        contradiction = true;
                    }
                    break;
                    case '=':
                    if(data_type[i] != 0) {
                        contradiction = true;
                    }
                    break;
                }
                break;
            }
        }

        if(!being) {
            data.push_back(temp);
            switch(oper) {
                case '>':
                data_type.push_back(1);
                break;
                case '<':
                data_type.push_back(-1);
                break;
                case '=':
                data_type.push_back(0);
                break;
            }
        }

        

        input(temp2);

        if(oper == '<') {
            for(int i = 0; i < 4; i++) {
                arr[temp2[i]]++;
            }
        } else if(oper == '>') {
            for(int i = 0; i < 4; i++) {
                arr[temp2[i]]--;
            }
        } else {
            for(int i = 0; i < 4; i++) {
                realCoin[temp2[i]] = true;;
            }
        }

        
        being = false;

        for(int i = 0; i < data.size(); i++) {
            if(data[i] == temp2) {
                being = true;
                switch(oper) {
                    case '<':
                    if(data_type[i] != 1) {
                        contradiction = true;
                    }
                    break;
                    case '>':
                    if(data_type[i] != -1) {
                        contradiction = true;
                    }
                    break;
                    case '=':
                    if(data_type[i] != 0) {
                        contradiction = true;
                    }
                    break;
                }
                break;
            }
        }

        if(!being) {
            data.push_back(temp2);
            switch(oper) {
                case '<':
                data_type.push_back(1);
                break;
                case '>':
                data_type.push_back(-1);
                break;
                case '=':
                data_type.push_back(0);
                break;
            }
        }

        


    }

    for(int i = 1; i <= 12; i++) {
        cout << i << " : " << arr[i] << '\t' << realCoin[i] << '\n';
    }


    int max = 0;
    int index = -1;
    bool isTween = false;
    bool isDefi = false;

    for(int i = 1; i <= 12; i++) {
        if(!realCoin[i]) {
            if(abs(max) < abs(arr[i])) {
                max = arr[i];
                index = i;
                isTween = false;
            } else if(abs(max) == abs(arr[i])) {
                isTween = true;
            }
        } 
    }
    
    //impossible 조건
    if(contradiction) {
        cout << "impossible";
        return 0;
    }

    if(abs(max) == 3 && !isTween){
        
        cout << index;
        if(arr[index] > 0) {
            cout << '+';
        } else {
            cout << '-';
        }

    }else {
        cout << "indefinite";
        return 0;
    }

    return 0;
}