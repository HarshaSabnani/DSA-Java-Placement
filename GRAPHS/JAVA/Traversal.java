import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class Traversal {

    public static List<Integer> BFS(List<List<Integer>> adj, int src) {
        int n = adj.size();

        List<Integer> result = new ArrayList<>();
        boolean[] visited = new boolean[n];
        Queue<Integer> queue = new LinkedList<>();

        if (src < 0 || src >= n) {
            return result;
        }

        queue.offer(src);
        visited[src] = true;

        while (!queue.isEmpty()) {
            int node = queue.poll();
            result.add(node);

            for (int neighbour : adj.get(node)) {
                if (!visited[neighbour]) {
                    visited[neighbour] = true;
                    queue.offer(neighbour);
                }
            }
        }

        return result;
    }

    private static void dfsHelper(
            int node,
            List<List<Integer>> adj,
            boolean[] visited,
            List<Integer> result) {

        visited[node] = true;
        result.add(node);

        for (int neighbour : adj.get(node)) {
            if (!visited[neighbour]) {
                dfsHelper(neighbour, adj, visited, result);
            }
        }
    }

    public static List<Integer> DFS(List<List<Integer>> adj, int src) {
        int n = adj.size();

        List<Integer> result = new ArrayList<>();
        boolean[] visited = new boolean[n];

        if (src < 0 || src >= n) {
            return result;
        }

        dfsHelper(src, adj, visited, result);
        return result;
    }

    public static void main(String[] args) {
        int vertices = 5;

        List<List<Integer>> adj = new ArrayList<>();

        for (int i = 0; i < vertices; i++) {
            adj.add(new ArrayList<>());
        }

        adj.get(0).add(1);
        adj.get(0).add(2);

        adj.get(1).add(0);
        adj.get(1).add(3);
        adj.get(1).add(4);

        adj.get(2).add(0);
        adj.get(3).add(1);
        adj.get(4).add(1);

        System.out.println("BFS Traversal: " + BFS(adj, 0));
        System.out.println("DFS Traversal: " + DFS(adj, 0));
    }
}