class Solution {
public:
    vector<vector<int>> graph; vector<int> tin, low; vector<vector<int>> bridges;
    int timer = 0;

    void dfs(int u, int parent) {
        tin[u] = low[u] = timer++;

        for (int v : graph[u]) {
            if (v == parent)
                continue;
            if (tin[v] != -1) {
                low[u] = min(low[u], tin[v]);
            } else {
                dfs(v, u);

                low[u] = min(low[u], low[v]);
                if (low[v] > tin[u]) {
                    bridges.push_back({u, v});
                }
            }
        }
    }
    vector<vector<int>> criticalConnections(
        int n,
        vector<vector<int>>& connections) {

        graph.resize(n);
        tin.assign(n, -1);
        low.resize(n);

        for (auto& edge : connections) {
            int u = edge[0];
            int v = edge[1];

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        dfs(0, -1);

        return bridges;
    }
};