#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;
int T, N;

struct RMQ {
    int n;
    vector<int> rangeMin;
    RMQ(const vector<int>& array) {
        n = array.size();
        rangeMin.resize(n * 4);
        init(array, 0, n - 1, 1);
    }
    int init(const vector<int>& array, int left, int right, int node) {
        if(left == right) return rangeMin[node] = array[left];

        int mid = (left + right) / 2;
        int leftMin = init(array, left, mid, node * 2);
        int rightMin = init(array, mid + 1, right, node * 2 + 1);
        return rangeMin[node] = min(leftMin, rightMin);
    }
    int query(int left, int right, int node, int nodeLeft, int nodeRight) {
        if(right < nodeLeft || nodeRight < left) return INT_MAX;
        if(left <= nodeLeft && nodeRight <= right) return rangeMin[node];
        int mid = (nodeLeft + nodeRight) / 2;
        return min(
            query(left, right, node * 2, nodeLeft, mid), 
            query(left, right, node * 2 + 1, mid + 1, nodeRight));
    }

    int query(int left, int right) {
        return query(left, right, 1, 0, n - 1);
    }

    int update(int index, int newValue, int node, int nodeLeft, int nodeRight) {
        if(index < nodeLeft || nodeRight < index) return rangeMin[node];
        if(nodeLeft == nodeRight) return rangeMin[node] = newValue;
        int mid = (nodeLeft + nodeRight) / 2;
        return rangeMin[node] = min(
            update(index, newValue, node * 2, nodeLeft, mid), 
            update(index, newValue, node * 2 + 1, mid + 1, nodeRight));
    }

    int update(int index, int newValue) {
        return update(index, newValue, 1, 0, n - 1);
    }
};



vector<vector<int>> adj;
vector<int> no2serial, serial2no, locInTrip, depth;
int nextSerial;


void traverse(int here, int d, vector<int>& trip) {

    no2serial[here] = nextSerial;
    serial2no[nextSerial] = here;
    nextSerial++;
    depth[here] = d;
    locInTrip[here] = trip.size();
    trip.push_back(no2serial[here]);

    for(int i = 0; i < adj[here].size(); i++) {
        traverse(adj[here][i], d + 1, trip);
        trip.push_back(no2serial[here]);
    }
}

RMQ* prepareRMQ(int start = 0) {
    
    no2serial.resize(adj.size());
    serial2no.resize(adj.size());
    locInTrip.resize(adj.size());
    depth.resize(adj.size());

    nextSerial = 0;
    vector<int> trip;
    traverse(start, 0, trip);
    return new RMQ(trip);
}

int distance(RMQ* rmq, int u, int v) {
    int lu = locInTrip[u], lv = locInTrip[v];
    if(lu > lv) swap(lu, lv);
    int lca = serial2no[rmq->query(lu, lv)];
    return depth[u] + depth[v] - 2 * depth[lca];
}


int main() {
    cin >> T;
    while(T--) {
        cin >> N;
        adj.assign(N + 1, vector<int>());
        vector<bool> hasParent(N + 1, false);

        int u, v;
        for(int i = 0; i < N - 1; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
            hasParent[v] = true;
        }

        int root = 0;
        for(int i = 1; i <= N; i++) {
            if(!hasParent[i]) {
                root = i;
                break;
            }
        }

        int a, b;
        cin >> a >> b;

        RMQ* rmq = prepareRMQ(root);
        cout << distance(rmq, a, b) << '\n';
        delete(rmq);


    }


    return 0;
}