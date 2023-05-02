#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

const int INF = INT_MAX;  // Define infinity as the maximum integer value

typedef pair<int, int> pii;  // Pair of integers for (distance, node) pairs

vector<pii> adj[100];  // Adjacency list to represent the graph

vector<int> dijkstra(int start, int n) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<int> dist(n + 1, INF);
    pq.push(make_pair(0, start));
    dist[start] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (auto v : adj[u]) {
            int alt = dist[u] + v.second;
            if (alt < dist[v.first]) {
                dist[v.first] = alt;
                pq.push(make_pair(dist[v.first], v.first));
            }
        }
    }

    return dist;
}

int main() {
    // Add edges to the graph
    adj[1].push_back(make_pair(1, 10));
    adj[1].push_back(make_pair(3, 5));
    adj[2].push_back(make_pair(3, 2));
    adj[2].push_back(make_pair(4, 1));
    adj[3].push_back(make_pair(2, 3));
    adj[3].push_back(make_pair(4, 9));
    adj[3].push_back(make_pair(5, 2));
    adj[4].push_back(make_pair(5, 4));
    adj[5].push_back(make_pair(4, 6));

    // Run Dijkstra's algorithm
    vector<int> dist = dijkstra(1, 5);

    // Print the shortest distance from node 1 to each node
    for (int i = 1; i <= 5; i++) {
        cout << "Shortest distance from node 1 to node " << i << " is " << dist[i] << endl;
    }

    return 0;
}
