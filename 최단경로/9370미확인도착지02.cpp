#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <climits>
#include <cstdio>
using namespace std;
#pragma warning(disable:4996)
typedef long long ll;

int num;
int n, m, t;
int s, g, h;
const int INF = 987654321;
vector< pair<int, int> > adj[2001];
vector<int> ends;
vector<int> result;
vector<int> dist;
vector<int> parent;

void dijkstra() {
   dist.clear();
   dist.assign(2001, INF);

   dist[s] = 0;

   // cost, here
   priority_queue<pair<int, int> > pq;
   pq.push({ 0, s });

   while (pq.empty() == false) {
      int here = pq.top().second;
      int cost = -pq.top().first;
      pq.pop();

      if (dist[here] < cost)
         continue;

      for (int i = 0; i < adj[here].size(); i++) {
         int there = adj[here][i].first;
         int nextCost = cost + adj[here][i].second;

         if (nextCost < dist[there]) {
            dist[there] = nextCost;
            pq.push({ -nextCost, there });

         }
      }
   }

   for (auto& end: ::ends) {
      if (dist[end] == INF)
         continue;

      queue<int> q;
      q.push(end);
      vector<bool> seen(2001, false);

      bool flag = false;

      while (q.empty() == false) {
         if (flag)
            break;
         int here = q.front();
         q.pop();

         if (seen[here])
            continue;

         seen[here] = true;

         // 최단 경로를 목적지 부터 도착지 까지 역으로 추적, g-h 경로를 지났는지 확인
         for (int i = 0; i < adj[here].size(); i++) {
            int there = adj[here][i].first;
            
            if (dist[there] + adj[here][i].second == dist[here]) {
               q.push(there);

               if ((here == g && there == h) ||
                  (here == h && there == g)) {
                  flag = true;
                  result.push_back(end);

                  break;
               }
            }

         }
      }
   }


}

int main() {
   cin >> num;
   while (num-- > 0) {
      cin >> n >> m >> t;
      cin >> s >> g >> h;

      for (int i = 0; i <= 2000; i++) 
         adj[i].clear();

      for (int i = 0; i < m; i++) {
         int a, b, d;
         scanf("%d %d %d", &a, &b, &d);
         adj[a].push_back({ b, d });
         adj[b].push_back({ a, d });
      }

      ::ends.clear();
      for (int i = 0; i < t; i++) {
         int end;
         cin >> end;
         ::ends.push_back(end);
      }

   
      dijkstra();

      sort(result.begin(), result.end());

      if (result.size() > 0) {
         for (auto& ret : result) {
            cout << ret << " ";
         }cout << endl;
      }

      result.clear();
   }

   return 0;
}