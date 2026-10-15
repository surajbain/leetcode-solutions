class Solution {
public:
    void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited) {

        visited[node] = true;

        for (int next : graph[node]) {
            if (!visited[next]) {
                dfs(next, graph, visited);
            }
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1)
            return -1;

        vector<vector<int>> graph(n);

        for (auto& edge : connections) {
            int u = edge[0];
            int v = edge[1];

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        vector<bool> visited(n, false);
        int components = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                components++;
                dfs(i, graph, visited);
            }
        }

        return components - 1;
    }
};