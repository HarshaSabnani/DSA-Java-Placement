import java.util.*;

public class Matrix01 {
    public int[][] updateMatrix(int[][] mat) {
        int m = mat.length;
        int n = mat[0].length;

        int[][] dist = new int[m][n];
        Queue<int[]> q = new LinkedList<>();

        for (int i = 0; i < m; i++) {
            Arrays.fill(dist[i], -1);

            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    dist[i][j] = 0;
                    q.offer(new int[]{i, j});
                }
            }
        }

        int[] dr = {-1, 1, 0, 0};
        int[] dc = {0, 0, -1, 1};

        while (!q.isEmpty()) {
            int[] cell = q.poll();
            int r = cell[0];
            int c = cell[1];

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < m &&
                    nc >= 0 && nc < n &&
                    dist[nr][nc] == -1) {

                    dist[nr][nc] = dist[r][c] + 1;
                    q.offer(new int[]{nr, nc});
                }
            }
        }

        return dist;
    }

    public static void main(String[] args) {
        int[][] mat = {
            {0, 0, 0},
            {0, 1, 0},
            {1, 1, 1}
        };

        Matrix01 obj = new Matrix01();
        int[][] ans = obj.updateMatrix(mat);

        System.out.println("Distance Matrix:");

        for (int[] row : ans) {
            for (int value : row) {
                System.out.print(value + " ");
            }
            System.out.println();
        }
    }
}