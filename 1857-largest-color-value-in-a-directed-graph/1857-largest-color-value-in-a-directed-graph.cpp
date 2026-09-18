class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<vector<int>> graph(n);
        vector<int> indegree(n, 0);

        for (auto &e : edges ) {
            graph[e[0]].push_back(e[1]);
            indegree[e[1]]++;
        }

        vector<vector<int>> dp(n, vector<int>(26, 0));
        queue<int> q;

        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        int ans = 0;
        int processed = 0;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            processed++;

            int color = colors[u] - 'a';
            dp[u][color]++;

            ans = max(ans, dp[u][color]);

            for (int v : graph[u] ) {
                for (int c = 0; c < 26; c++) {
                    dp[v][c] = max(dp[v][c], dp[u][c]);
                }
                indegree[v]--;

                if (indegree[v]== 0) {
                    q.push(v);
                }
            }
            
        }
        if (processed != n) {
            return -1;
        }
        return ans;
    }
};