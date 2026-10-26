import java.util.ArrayList;
import java.util.List;

public class Representation {
    public static void main(String[] args) {
        int vertices = 5;

        int[][] edges = {
            {0, 1},
            {0, 2},
            {1, 3},
            {1, 4}
        };

        // Adjacency Matrix
        int[][] matrix = new int[vertices][vertices];

        for (int[] edge : edges) {
            int u = edge[0];
            int v = edge[1];

            matrix[u][v] = 1;
            matrix[v][u] = 1;
        }

        System.out.println("Adjacency Matrix:");

        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                System.out.print(matrix[i][j] + " ");
            }
            System.out.println();
        }

        // Adjacency List
        List<List<Integer>> adj = new ArrayList<>();

        for (int i = 0; i < vertices; i++) {
            adj.add(new ArrayList<>());
        }

        for (int[] edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj.get(u).add(v);
            adj.get(v).add(u);
        }

        System.out.println("\nAdjacency List:");

        for (int i = 0; i < vertices; i++) {
            System.out.println(i + " -> " + adj.get(i));
        }
    }
}