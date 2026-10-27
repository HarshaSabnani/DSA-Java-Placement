#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
int dfs(int r, int c, vector<vector<int>>& grid) {
if (r < 0 || c < 0 ||
r >= grid.size() || c >= grid[0].size() ||
grid[r][c] == 0) {
return 0;
}

    grid[r][c] = 0;

    int area = 1;
    area += dfs(r + 1, c, grid);
    area += dfs(r - 1, c, grid);
    area += dfs(r, c + 1, grid);
    area += dfs(r, c - 1, grid);

    return area;
}

int maxAreaOfIsland(vector<vector<int>>& grid) {
    if (grid.empty() || grid[0].empty()) {
        return 0;
    }

    int ans = 0;

    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (grid[i][j] == 1) {
                ans = max(ans, dfs(i, j, grid));
            }
        }
    }

    return ans;
}

};

int main() {
Solution solution;
vector<vector<int>> grid = {
    {0, 0, 1, 0, 0, 0, 1},
    {0, 1, 1, 0, 0, 1, 1},
    {0, 0, 0, 0, 0, 0, 0},
    {1, 1, 0, 0, 1, 0, 0}
};

cout << "Maximum Area of Island: "
     << solution.maxAreaOfIsland(grid) << endl;

return 0;
}
