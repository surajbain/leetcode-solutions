class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {

        vector<vector<int>> adj(n + 1);
        vector<int> indegree(n + 1, 0);
        vector<int> dp(n + 1, 0);
        for (auto& edge : relations) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;
        for (int i = 1; i <= n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
                dp[i] = time[i - 1];
            }
        }

        int ans = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            ans = max(ans, dp[node]);

            for (int neighbor : adj[node]) {

                dp[neighbor] = max(
                    dp[neighbor],
                    dp[node] + time[neighbor - 1]
                );

                indegree[neighbor]--;

                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        return ans;
    }
};