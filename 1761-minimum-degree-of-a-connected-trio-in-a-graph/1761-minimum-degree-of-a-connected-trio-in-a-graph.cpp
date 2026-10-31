class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        vector<vector<bool>> adj(
            n + 1, vector<bool>(n + 1, false)
        );

        vector<int> degree(n + 1, 0);

        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u][v] = true;
            adj[v][u] = true;

            degree[u]++;
            degree[v]++;
        }

        int ans = INT_MAX;

        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (!adj[i][j]) {
                    continue;
                }

                for (int k = j + 1; k <= n; k++) {
                    if (adj[i][k] && adj[j][k]) {
                        int trioDegree =
                            degree[i] + degree[j] + degree[k] - 6;

                        ans = min(ans, trioDegree);
                    }
                }
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};