class Solution {
public:
    void dfs(int node, int source,
             vector<vector<int>>& adj,
             vector<bool>& visited,
             vector<vector<int>>& ans) {

        visited[node] = true;

        for (int next : adj[node]) {
            if (!visited[next]) {
                visited[next] = true;
                ans[next].push_back(source);

                dfs(next, source, adj, visited, ans);
            }
        }
    }

    vector<vector<int>> getAncestors(
        int n,
        vector<vector<int>>& edges
    ) {
        vector<vector<int>> adj(n);
        vector<vector<int>> ans(n);

        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
        }

        for (int i = 0; i < n; i++) {
            vector<bool> visited(n, false);

            dfs(i, i, adj, visited, ans);
        }

        return ans;
    }
};