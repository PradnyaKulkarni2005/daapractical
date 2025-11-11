#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

// Dijkstra’s Algorithm
void dijkstra(int n, vector<vector<pair<int, int>>>& graph, int source) {
    vector<int> dist(n + 1, INT_MAX);  // Distance from source
    dist[source] = 0;

    // Min-heap: (distance, node)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});

    while (!pq.empty()) {
        int currentDist = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        // Skip outdated distances
        if (currentDist > dist[node])
            continue;

        // Check all neighbors
        for (auto& neighbor : graph[node]) {
            int nextNode = neighbor.first;
            int weight = neighbor.second;

            // Relaxation step
            if (dist[nextNode] > currentDist + weight) {
                dist[nextNode] = currentDist + weight;
                pq.push({dist[nextNode], nextNode});
            }
        }
    }

    cout << "\nShortest travel time from source (" << source << ") to all intersections:\n";
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INT_MAX)
            cout << "Intersection " << i << " is unreachable.\n";
        else
            cout << "To intersection " << i << " -> " << dist[i] << " minutes\n";
    }
}

int main() {
    int n, m;
    cout << "Enter number of intersections (nodes): ";
    cin >> n;
    cout << "Enter number of roads (edges): ";
    cin >> m;

    vector<vector<pair<int, int>>> graph(n + 1);

    cout << "\nEnter road connections (u v w):\n";
    cout << "u = from intersection, v = to intersection, w = travel time\n";
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w}); // assuming two-way roads
    }

    int source;
    cout << "\nEnter ambulance location (source node): ";
    cin >> source;

    dijkstra(n, graph, source);

    return 0;
}
