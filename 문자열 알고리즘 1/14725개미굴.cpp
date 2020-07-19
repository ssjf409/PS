#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct Node {
    map<string, Node*> data;
};

void dfs(Node* cur, int depth) {
    map<string, Node*>::iterator iter;
    for(iter = cur->data.begin(); iter != cur->data.end(); iter++) {
        for(int i = 0; i < depth; i++) {
            cout << "--";
        }
        cout << iter->first << '\n';
        dfs(iter->second, depth + 1);
    }
}

int main() {
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;

    Node* head = new Node();
    Node* cur;

    for(int i = 0; i < N; i++) {
        int depth;
        cin >> depth;
        string str;

        cur = head;
        for(int j = 0; j < depth; j++) {
            cin >> str;
            if(cur->data.find(str) == cur->data.end()) {
                Node* newNode = new Node();
                cur->data.insert({str, newNode});
                cur = newNode;
            } else {
                cur = cur->data[str];
            }
        }
    }
    
    dfs(head, 0);
}