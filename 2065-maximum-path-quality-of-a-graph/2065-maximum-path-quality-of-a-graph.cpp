class Solution {
public:
    vector<vector<pair<int, int>>> adj;
    vector<int> visited;
    int ans = 0;

    void dfs(int node, int time, int quality, int maxTime, vector<int>& values) {

        if (node == 0) {
            ans = max(ans, quality);
        }

        for (auto [next, travelTime] : adj[node]) {

            if (time + travelTime > maxTime) {
                continue;
            }

            bool firstVisit = (visited[next] == 0);

            visited[next]++;

            int newQuality = quality;

            if (firstVisit) {
                newQuality += values[next];
            }

            dfs(next, time + travelTime,
                newQuality, maxTime, values);
            visited[next]--;
        }
    }

    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {

        int n = values.size();

        adj.assign(n, {});
        visited.assign(n, 0);

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int t = edge[2];

            adj[u].push_back({v, t});
            adj[v].push_back({u, t});
        }

        visited[0] = 1;

        dfs(0, 0, values[0], maxTime, values);

        return ans;
    }
};