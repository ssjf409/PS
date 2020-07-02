#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <cstdio>
#define MAX 10000

using namespace std;

bool visited[MAX];
int parent[MAX];
int command[MAX];
vector<int> comPath;

int test, A, B;

inline int getNext(int cur, int dir) {
    switch(dir) {
        case 0:
            return (cur * 2) % MAX;
            break;
        case 1:
            if(cur == 0) return 9999;
            return cur - 1;
            break;
        case 2:
            return (cur % 1000) * 10 + cur / 1000;
            break;
        case 3:
            return (cur % 10) * 1000 + cur / 10;
            break;
    }
}


inline void printCom(int com) {
    switch(com) {
        case 0:
            printf("D");
            break;
        case 1:
            printf("S");
            break;
        case 2:
            printf("L");
            break;
        case 3:
            printf("R");
            break;
    }
}



int getMinCommand(int start) {
    queue<int> q;
    visited[start] = true;
    q.push(start);

    int cnt = 0;

    while(!q.empty()) {
        int qSize = q.size();
        for(int i = 0; i < qSize; i++) {
            int cur = q.front();
            q.pop();

            if(cur == B) {
                int temp = B;

                while(temp != A) {
                    comPath.push_back(command[temp]);
                    temp = parent[temp];
                }

                return cnt;
            }

            for(int dir = 0; dir < 4; dir++) {
                int next = getNext(cur, dir);
                if(next < 0 || next >= MAX) continue;
                if(visited[next]) continue;
                visited[next] = true;
                parent[next] = cur;
                command[next] = dir;
                q.push(next);
            }
        }
        cnt++;
    }

    return -1;
}


int main() {
    cin >> test;

    for(int testCase = 0; testCase < test; testCase++) {
        cin >> A >> B;

        memset(visited, false, sizeof(visited));
        memset(parent, -1, sizeof(parent));
        memset(command, -1, sizeof(command));
        comPath.clear();

        getMinCommand(A);
        
        for(int i = comPath.size() - 1; i >= 0; i--) {
            printCom(comPath[i]);
        }
        cout << '\n';
        
    }

    return 0;
}