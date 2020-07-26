#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
vector<int> no2serial, serial2no, locInTrip, depth;
int nextSerial;

struct RMQ {
    int n;
    vector<int> rangeMin;

    RMQ(const vector<int>& arr) {
        n = arr.size();
        rangeMin.resize(n * 4);
        init(arr, 0, n - 1, 1);
    }
    
    int init(const vector<int>& arr, int left, int right, int node) {
        if(left == right) return rangeMin[node] = arr[left];

        int mid = (left + right) / 2;
        int leftMin = init(arr, left, mid, node * 2);
        int rightMin = init(arr, mid + 1, right, node * 2 + 1);
        return rangeMin[node] = min(leftMin, rightMin);
    }

    int query(int left, int right, int node, int leftNode, int rightNode) {
        if(rightNode < left || right < leftNode) return INT_MAX;
        if(left <= leftNode && rightNode <= right) return rangeMin[node];
        int mid = (leftNode + rightNode) / 2;
        return min(
            query(left, right, node * 2, leftNode, mid),
            query(left, right, node * 2 + 1, mid + 1, rightNode));
    }
    int query(int left, int right) {
        return query(left, right, 1, 0, n - 1);
    }

    int update(int index, int newValue, int node, int leftNode, int rightNode) {
        if(index < leftNode || rightNode < index) return rangeMin[node];
        if(leftNode == rightNode) return rangeMin[node] = newValue;
        int mid = (leftNode + rightNode) / 2;
        return rangeMin[node] = min(
            update(index, newValue, node * 2, leftNode, mid),
            update(index, newValue, node * 2 + 1, mid + 1, rightNode));
    }
    int update(int index, int newValue) {
        return update(index, newValue, 1, 0, n - 1);
    }
};

void traverse(int here, int d, vector<int>& trip) {
    no2serial[here] = nextSerial;
    serial2no[nextSerial] = here;
    nextSerial++;
    depth[here] = d;
    locInTrip[here] = trip.size();
    trip.push_back(no2serial[here]);

    for(int i = 0; i < adj[here].size(); i++) {
        if(visited[adj[here][i]]) continue;
        visited[adj[here][i]] = true;
        traverse(adj[here][i], d + 1, trip);
        trip.push_back(no2serial[here]);
    }
}

RMQ* prepareRMQ(int start = 0) {
    nextSerial = 0;
    vector<int> trip;
    visited[start] = true;
    traverse(start, 0, trip);

    return new RMQ(trip);
}

int getLCA(RMQ* rmq, int u, int v) {
    int lu = locInTrip[u], lv = locInTrip[v];
    if(lu > lv) swap(lu, lv);
    return serial2no[rmq->query(lu, lv)];
    // return depth[u] + depth[v] - 2 * depth[lca];
}

int main () {
    // ios_base :: sync_with_stdio(false); 
    // cin.tie(NULL); cout.tie(NULL);
    int N, M;
    cin >> N;

    adj.assign(N + 1, vector<int>());
    visited.assign(N + 1, false);
    
    no2serial.assign(N + 1, 0);
    serial2no.assign(N + 1, 0);
    locInTrip.assign(N + 1, 0);
    depth.assign(N + 1, 0);


    
    int u, v;
    for(int i = 0; i < N - 1; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    RMQ* rmq = prepareRMQ(1);

    cin >> M;
    
    for(int i = 0; i < M; i++) {
        cin >> u >> v;
        cout << getLCA(rmq, u, v) << '\n';
    }



    return 0;
}