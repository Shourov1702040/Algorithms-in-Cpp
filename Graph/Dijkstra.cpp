
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int nodes, edges, start_node;
    cout << "Enter number of nodes and edges: ";
    cin >> nodes >> edges;

    vector<pair<int, int>> adj[nodes];
    cout << "Enter edges (source, destination, weight):" << endl;
    for (int i = 0; i < edges; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    cout << "Enter starting node: ";
    cin >> start_node;

    vector<int> dist(nodes, 1e9);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[start_node] = 0;
    pq.push({0, start_node});

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "Shortest distances from node " << start_node << ":" << endl;
    for (int i = 0; i < nodes; i++) {
        cout << "Node " << i << " : " << dist[i] << endl;
    }

    return 0;
}
