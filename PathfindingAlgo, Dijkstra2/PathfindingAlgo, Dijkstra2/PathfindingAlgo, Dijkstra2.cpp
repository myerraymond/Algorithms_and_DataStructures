#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

typedef pair<int, int> pii;

vector<vector<pii>> adjList; // adjacency list representation of graph
vector<int> dist; // distance array
vector<bool> visited; // visited array
priority_queue<pii, vector<pii>, greater<pii>> pq; // min-priority queue

void dijkstra(int start) {
    // initialize distance array and visited array
    dist.assign(adjList.size(), INF);
    visited.assign(adjList.size(), false);
    dist[start] = 0;

    // push start node onto priority queue
    pq.push(make_pair(0, start));

    // run dijkstra's algorithm
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (visited[u]) continue;
        visited[u] = true;

        for (auto edge : adjList[u]) {
            int v = edge.first;
            int w = edge.second;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
}

int main() {
    int n, m, start;
    cin >> n >> m >> start;

    adjList.resize(n);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adjList[u].push_back(make_pair(v, w));
    }

    dijkstra(start);

    for (int i = 0; i < n; i++) {
        if (dist[i] == INF) cout << "INF" << endl;
        else cout << dist[i] << endl;
    }

    return 0;
}
