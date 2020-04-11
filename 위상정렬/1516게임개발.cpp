    #include <iostream>
    #include <vector>
    #include <queue>

    using namespace std;

    void addEdge(vector<vector<int>>& adj_list, vector<int>& indegree, int u, int v) {
        adj_list[u].push_back(v);
        indegree[v]++;
    }

    vector<int> topologicalSort(const vector<vector<int>>& adj_list, vector<int>& indegree, vector<int>& time) {
        int N = indegree.size() - 1;
        vector<int> ret;

        vector<int> sum(N + 1, 0);

        queue<int> q;
        for(int i = 1; i <= N; i++) {
            if(indegree[i] == 0) q.push(i);
        }

        for(int i = 0; i < N; i++) {
            if(q.empty()) {
                cout << "has cycle";
                return ret;
            }
            int current = q.front();
            q.pop();
            ret.push_back(current);
            sum[current] += time[current];
            for(int j = 0; j < adj_list[current].size(); j++) {
                int next = adj_list[current][j];
                if(sum[next] < sum[current]) {
                    sum[next] = sum[current];
                }
                if(--indegree[next] == 0) {
                    q.push(next);
                }
            }
        
        }
        return sum;
    }

    int main() {
        int N;
        cin >> N;
        
        vector<vector<int>> adj_list(N + 1, vector<int>());
        vector<int> indegree(N + 1, 0);
        vector<int> time(N + 1);
        vector<int> result;

        int orderNum;
        for(int i = 1; i <= N; i++) {
            cin >> time[i];
            while(true) {
                cin >> orderNum;
                if(orderNum == -1) break;
                addEdge(adj_list, indegree, orderNum, i); 
            }
        }

        result = topologicalSort(adj_list, indegree, time);

        for(int i = 1; i < result.size(); i++) {
            cout << result[i] << '\n';
        }
    }