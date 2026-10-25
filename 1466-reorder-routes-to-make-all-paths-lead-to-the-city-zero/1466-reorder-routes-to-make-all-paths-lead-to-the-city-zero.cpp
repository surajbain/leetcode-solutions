class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> graph(n);

        for (auto& edge : connections) {
            int u = edge[0];
            int v = edge[1];

            graph[u].push_back({v, 1});
            graph[v].push_back({u, 0});
        }

        vector<bool> visited(n, false);
        int changes = 0;

        function<void(int)> dfs = [&](int node) {
            visited[node] = true;

            for (auto [neighbor, cost] : graph[node]) {
                if (!visited[neighbor]) {
                    changes += cost;
                    dfs(neighbor);
                }
            }
        };

        dfs(0);

        return changes;
    }
};