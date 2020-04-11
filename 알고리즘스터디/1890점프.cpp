#include <iostream>
#include <cstring>

using namespace std;

int N;
int board[100][100];
long long cache[100][100];


long long getPath(int y, int x) {
    if(y == N - 1 && x == N - 1) return 1;
    long long& ret = cache[y][x];
    if(ret != -1) return ret;

    ret = 0;

    if(board[y][x] == 0) return ret;



    if(y + board[y][x] < N) {
        ret += getPath(y + board[y][x], x);
    }
    if(x + board[y][x] < N) {
        ret += getPath(y, x + board[y][x]);
    }
    return ret;
}


int main() {
    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    memset(cache, -1, sizeof(cache));

    cout << getPath(0, 0);

    return 0;
}
/*
#include<iostream>
#include<string.h>
using namespace std;

long long d[101][101];
long long a[101][101];
int n;

int main()
{
    
    cin >> n;
    
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    
    d[1][1] = 1;
    
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            long long jump = a[i][j];
            
            if(i ==n && j == n)
            {
                break;
            }
            
            if(i + jump <= n)
            {
                d[i + jump][j]  += d[i][j];
            }
            
            if(j + jump <= n)
            {
                d[i][j + jump]  += d[i][j];
            }
        }
    }
    
    
    cout << d[n][n] << "\n";
}*/