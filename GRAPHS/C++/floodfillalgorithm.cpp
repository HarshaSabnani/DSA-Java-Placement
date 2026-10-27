#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    void dfs(int row, int col, vector<vector<int>>& ans,
             vector<vector<int>>& image, int newColor,
             int delRow[], int delCol[], int iniColor) {

        ans[row][col] = newColor;

        int n = image.size();
        int m = image[0].size();

        for (int i = 0; i < 4; i++) {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];

            if (nrow >= 0 && nrow < n &&
                ncol >= 0 && ncol < m &&
                image[nrow][ncol] == iniColor &&
                ans[nrow][ncol] != newColor) {

                dfs(nrow, ncol, ans, image, newColor,
                    delRow, delCol, iniColor);
            }
        }
    }

public:
    vector<vector<int>> floodfill(vector<vector<int>>& image,
                                  int sr, int sc, int newColor) {

        int iniColor = image[sr][sc];

        if (iniColor == newColor) {
            return image;
        }

        vector<vector<int>> ans = image;

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        dfs(sr, sc, ans, image, newColor,
            delRow, delCol, iniColor);

        return ans;
    }
};

int main() {
    Solution solution;

    vector<vector<int>> image = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}
    };

    int sr = 1;
    int sc = 1;
    int newColor = 2;

    vector<vector<int>> result =
        solution.floodfill(image, sr, sc, newColor);

    cout << "Flood Fill Result:\n";

    for (const auto& row : result) {
        for (int pixel : row) {
            cout << pixel << " ";
        }
        cout << endl;
    }

    return 0;
}