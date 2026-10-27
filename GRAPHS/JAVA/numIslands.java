import java.util.LinkedList;
import java.util.Queue;

public class numIslands {
public static void bfs(int row, int col, char[][] grid) {
    int m = grid.length;
    int n = grid[0].length;

    Queue<int[]> q = new LinkedList<>();
    q.offer(new int[]{row, col});
    grid[row][col] = '0';

    int[] delRow = {-1, 0, 1, 0};
    int[] delCol = {0, 1, 0, -1};

    while (!q.isEmpty()) {
        int[] cell = q.poll();
        int r = cell[0];
        int c = cell[1];

        for (int i = 0; i < 4; i++) {
            int nr = r + delRow[i];
            int nc = c + delCol[i];

            if (nr >= 0 && nr < m &&
                nc >= 0 && nc < n &&
                grid[nr][nc] == '1') {

                grid[nr][nc] = '0';
                q.offer(new int[]{nr, nc});
            }
        }
    }
}

public static int numIslands(char[][] grid) {
    if (grid == null || grid.length == 0 || grid[0].length == 0) {
        return 0;
    }

    int m = grid.length;
    int n = grid[0].length;
    int count = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '1') {
                count++;
                bfs(i, j, grid);
            }
        }
    }

    return count;
}

public static void main(String[] args) {
    char[][] grid = {
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}
    };

    System.out.println("Number of Islands: " + numIslands(grid));
}
}
