#include <cstdio>

using namespace std;

int parent[201];
int N, M;

int findParent(int a) {
    if(parent[a] == a) return a;
    return parent[a] = findParent(parent[a]);
}

void unionParent(int a, int b) {
    a = findParent(a);
    b = findParent(b);

    if(a > b) parent[a] = b;
    else parent[b] = a;
}


int main() {
    scanf("%d %d", &N, &M);

    for(int i = 1; i <= N; i++) {
        parent[i] = i;
    }

    int conn;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            scanf("%d", &conn);
            if(conn) {
                unionParent(i, j);
            }
        }
    }
    
    int arr[1001];
    for(int i = 0; i < M; i++) {
        scanf("%d", &arr[i]);
    }

    for(int i = 1; i < M; i++) {
        if(findParent(arr[i - 1]) != findParent(arr[i])) {
            printf("NO");
            return 0;
        }
    }

    printf("YES");


    return 0;
}
