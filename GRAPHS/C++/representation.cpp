#include <iostream>
#include <vector>
using namespace std;

int main() {
    int vertices = 5;

    // Adjacency Matrix
    vector<vector<int>> matrix(vertices, vector<int>(vertices, 0));

    vector<pair<int, int>> edges = {
        {0, 1},
        {0, 2},
        {1, 3},
        {1, 4}
    };

    for (auto edge : edges) {
        int u = edge.first;
        int v = edge.second;

        matrix[u][v] = 1;
        matrix[v][u] = 1;
    }

    cout << "Adjacency Matrix:\n";

    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // Adjacency List
    vector<vector<int>> adj(vertices);

    for (auto edge : edges) {
        int u = edge.first;
        int v = edge.second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << "\nAdjacency List:\n";

    for (int i = 0; i < vertices; i++) {
        cout << i << " -> ";

        for (int neighbour : adj[i]) {
            cout << neighbour << " ";
        }

        cout << endl;
    }

    return 0;
}

