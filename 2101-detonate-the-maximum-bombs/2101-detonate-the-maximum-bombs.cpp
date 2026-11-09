class Solution {
public:
    vector<vector<int>> adj;
    vector<bool> visited;

    int dfs(int node) {
        visited[node] = true;

        int count = 1;

        for (int next : adj[node]) {
            if (!visited[next]) {
                count += dfs(next);
            }
        }

        return count;
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();

        adj.resize(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;

                long long dx = bombs[i][0] - bombs[j][0];
                long long dy = bombs[i][1] - bombs[j][1];
                long long r = bombs[i][2];

                if (dx * dx + dy * dy <= r * r) {
                    adj[i].push_back(j);
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            visited.assign(n, false);

            ans = max(ans, dfs(i));
        }

        return ans;
    }
};