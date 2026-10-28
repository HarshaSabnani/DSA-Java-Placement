#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> dist(m, vector<int>(n, -1));
        queue<pair<int, int>> q;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    dist[i][j] = 0;
                    q.push(make_pair(i, j));
                }
            }
        }

        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        while (!q.empty()) {
            pair<int, int> cell = q.front();
            q.pop();

            int r = cell.first;
            int c = cell.second;

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < m &&
                    nc >= 0 && nc < n &&
                    dist[nr][nc] == -1) {

                    dist[nr][nc] = dist[r][c] + 1;
                    q.push(make_pair(nr, nc));
                }
            }
        }

        return dist;
    }
};

int main() {
    vector<vector<int>> mat;
    mat.push_back(vector<int>{0, 0, 0});
    mat.push_back(vector<int>{0, 1, 0});
    mat.push_back(vector<int>{1, 1, 1});

    Solution obj;
    vector<vector<int>> ans = obj.updateMatrix(mat);

    cout << "Distance Matrix:" << endl;

    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
