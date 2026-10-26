#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
void dfs(int src, vector<vector<int>>& adj, vector<bool>& visited) {
visited[src] = true;
    for (int i = 0; i < adj.size(); i++) {
        if (adj[src][i] == 1 && !visited[i]) {
            dfs(i, adj, visited);
        }
    }
}

void bfs(int src, vector<vector<int>>& adj, vector<bool>& visited) {
    queue<int> q;
    q.push(src);
    visited[src] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v = 0; v < adj.size(); v++) {
            if (adj[u][v] == 1 && !visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

int numProvinces(vector<vector<int>>& adj) {
    int n = adj.size();
    vector<bool> visited(n, false);
    int provinces = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, adj, visited);
            provinces++;
        }
    }

    return provinces;
}

};

int main() {
vector<vector<int>> adj = {
{1, 1, 0},
{1, 1, 0},
{0, 0, 1}
};


Solution solution;
cout << "Number of Provinces: "
     << solution.numProvinces(adj) << endl;

return 0;


}
