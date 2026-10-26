import java.util.*;

public class numProvinces {
public static void dfs(int node, ArrayList<ArrayList<Integer>> adj, boolean[] visited) {
visited[node] = true;

    for (int neighbour : adj.get(node)) {
        if (!visited[neighbour]) {
            dfs(neighbour, adj, visited);
        }
    }
}

public static int numProvinces(ArrayList<ArrayList<Integer>> adj, int v) {
    boolean[] visited = new boolean[v];
    int provinces = 0;

    for (int i = 0; i < v; i++) {
        if (!visited[i]) {
            dfs(i, adj, visited);
            provinces++;
        }
    }

    return provinces;
}

public static void main(String[] args) {
    ArrayList<ArrayList<Integer>> adj = new ArrayList<>();

    adj.add(new ArrayList<>(Arrays.asList(1, 1, 0)));
    adj.add(new ArrayList<>(Arrays.asList(1, 1, 0)));
    adj.add(new ArrayList<>(Arrays.asList(0, 0, 1)));

    System.out.println("Number of Provinces: " + numProvinces(adj, 3));
}

}
