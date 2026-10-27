public class maxAreaOfIsland {

public static int dfs(int r, int c, int[][] grid) {
    if (r < 0 || c < 0 || r >= grid.length ||
        c >= grid[0].length || grid[r][c] == 0) {
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

public static int maxAreaOfIsland(int[][] grid) {
    if (grid == null || grid.length == 0 || grid[0].length == 0) {
        return 0;
    }

    int maxArea = 0;

    for (int i = 0; i < grid.length; i++) {
        for (int j = 0; j < grid[0].length; j++) {
            if (grid[i][j] == 1) {
                maxArea = Math.max(maxArea, dfs(i, j, grid));
            }
        }
    }

    return maxArea;
}

public static void main(String[] args) {
    int[][] grid = {
        {0, 0, 1, 0, 0, 0, 1},
        {0, 1, 1, 0, 0, 1, 1},
        {0, 0, 0, 0, 0, 0, 0},
        {1, 1, 0, 0, 1, 0, 0}
    };

    System.out.println("Maximum Area of Island: " + maxAreaOfIsland(grid));
}

}
