#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> BFS(vector<vector<int>>& adj, int src) {
        int n = adj.size();
        vector<bool> visited(n, false);
        vector<int> result;
        queue<int> q;

        if (src < 0 || src >= n) {
            return result;
        }

        q.push(src);
        visited[src] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            result.push_back(node);

            for (int neighbour : adj[node]) {
                if (!visited[neighbour]) {
                    visited[neighbour] = true;
                    q.push(neighbour);
                }
            }
        }

        return result;
    }

    void dfsHelper(int node, vector<vector<int>>& adj,
                   vector<bool>& visited, vector<int>& result) {
        visited[node] = true;
        result.push_back(node);

        for (int neighbour : adj[node]) {
            if (!visited[neighbour]) {
                dfsHelper(neighbour, adj, visited, result);
            }
        }
    }

    vector<int> DFS(vector<vector<int>>& adj, int src) {
        int n = adj.size();
        vector<bool> visited(n, false);
        vector<int> result;

        if (src < 0 || src >= n) {
            return result;
        }

        dfsHelper(src, adj, visited, result);
        return result;
    }
};

int main() {
    int vertices = 5;
    vector<vector<int>> adj(vertices);

    adj[0] = {1, 2};
    adj[1] = {0, 3, 4};
    adj[2] = {0};
    adj[3] = {1};
    adj[4] = {1};

    Solution solution;

    vector<int> bfs = solution.BFS(adj, 0);
    vector<int> dfs = solution.DFS(adj, 0);

    cout << "BFS Traversal: ";
    for (int node : bfs) {
        cout << node << " ";
    }

    cout << "\nDFS Traversal: ";
    for (int node : dfs) {
        cout << node << " ";
    }

    cout << endl;
    return 0;
}