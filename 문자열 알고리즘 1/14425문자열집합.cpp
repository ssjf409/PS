#include <iostream>
#include <vector>

using namespace std;

struct Node {
    bool data = false;
    vector<Node*> next;

    Node() {
        data = false;
        next.assign(26, nullptr);
    }
};

void makeNode(Node* cur, const string& str, int index) {
    if(index == str.size()) {
        cur->data = true;
        return;
    }
    if(cur->next[str[index] - 'a'] == nullptr) {
        cur->next[str[index] - 'a'] = new Node();
    }
    makeNode(cur->next[str[index] - 'a'], str, index + 1);
}

bool findNode(Node* cur, const string& str, int index) {
    if(index == str.size()) {
        if(cur->data) return true;
        return false;
    }

    if(cur->next[str[index] - 'a'] == nullptr) return false;
    return findNode(cur->next[str[index] - 'a'], str, index + 1);
}

int main() {
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    Node* head = new Node();

    string str;
    for(int i = 0; i < N; i++) {
        cin >> str;
        makeNode(head, str, 0);
    }

    int cnt = 0;
    for(int i = 0; i < M; i++) {
        cin >> str;
        if(findNode(head, str, 0)) cnt++;
    }

    cout << cnt;

    return 0;
}