#include <iostream>
#include <vector>

using namespace std;

int main() {
    int nodes, edges, start_node;
    cout << "Enter number of nodes and edges: ";
    cin >> nodes >> edges;

    vector<vector<int>> edge_list;
    cout << "Enter edges (source, destination, weight):" << endl;
    for (int i = 0; i < edges; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edge_list.push_back({u, v, w});
    }

    cout << "Enter starting node: ";
    cin >> start_node;

    vector<int> dist(nodes, 1e9);
    dist[start_node] = 0;

    for (int i = 0; i < nodes - 1; i++) {
        for (auto e : edge_list) {
            if (dist[e[0]] != 1e9 && dist[e[0]] + e[2] < dist[e[1]]) {
                dist[e[1]] = dist[e[0]] + e[2];
            }
        }
    }

    cout << "Shortest distances from node " << start_node << ":" << endl;
    for (int i = 0; i < nodes; i++) {
        cout << "Node " << i << " : " << (dist[i] == 1e9 ? -1 : dist[i]) << endl;
    }

    return 0;
}
