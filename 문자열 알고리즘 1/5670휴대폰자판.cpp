#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define ALPHA_NUM 26

using namespace std;

struct TrieNode {
    bool finish;
    int childrenCnt = 0;
    TrieNode* next[ALPHA_NUM];

    TrieNode() : finish(false), childrenCnt(0) {
        memset(next, (int)NULL, sizeof(next));
    }
    ~TrieNode() {
        for(int i = 0; i < ALPHA_NUM; i++) {
            if(next[i]) delete next[i];
        }
    }

    void insertNode(const char* key) {
        if(*key == '\0') {
            finish = true;
        } else {
            int cur = *key - 'a';
            if(next[cur] == NULL) {
                next[cur] = new TrieNode();
                childrenCnt++;
            }
            next[cur]->insertNode(key + 1);
        }
    }

    TrieNode* findNode(const char* key) {
        if(*key == '\0') return this;
        int cur = *key - 'a';
        if(next[cur] == NULL) return NULL;
        return next[cur]->findNode(key + 1);
    }

    int getTotalCnt(const char* key) {
        if(*key == '\0') return 0;
        
        
    }
};

int main() {
    int n;
    while(cin >> n) {
        TrieNode* head = new TrieNode();
        vector<string> words(n, "");
        for(int i = 0; i < n; i++) {
            cin >> words[i];
            head->insertNode(words[i].c_str());
        }

        for(int i = 0; i < n; i++) {
            cout << head->getTotalCnt(words[i].c_str()) << '\n';
        }

        // sort(words.begin(), words.end());
        
        delete head;
    }

    return 0;
}