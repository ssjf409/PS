#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <memory.h>
 
using namespace std;
 
vector<int> vc[1000002];
int dp[1000002][2];
 
int dy(int prev, int here, bool chk)
{
    int &ret = dp[here][chk];
 
    if (ret != -1)
        return ret;
 
    ret = 0;
    
    for (int i = 0; i < vc[here].size(); i++)
    {
        int next = vc[here][i];
 
        if (next == prev)
            continue;
 
        if (chk)
            ret += dy(here, next, 0);
        else if (!chk)
            ret += max(dy(here, next, 1) + 1, dy(here, next, 0));
    }
 
    return ret;
}
 
int main()
{
    int n;
    scanf("%d", &n);
 
    for (int i = 0; i < n - 1; i++)
    {
        int from, to;
        scanf("%d %d", &from, &to);
 
        vc[from].push_back(to);
        vc[to].push_back(from);
    }
 
    memset(dp, -1, sizeof(dp));
 
    printf("%d", n - max(dy(-1, 1, 0), dy(-1, 1, 1) + 1));
 
    return 0;
}
