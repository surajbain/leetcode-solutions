class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        
        int n = passingFees.size();

        vector<vector<pair<int, int>>> adj(n);

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int t = edge[2];

            adj[u].push_back({v, t});
            adj[v].push_back({u, t});
        }
        const int INF = 1e9;
        vector<vector<int>> dp(maxTime + 1, vector<int>(n, INF));
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,greater<tuple<int, int, int>>> pq;

        dp[0][0] = passingFees[0];
        pq.push({passingFees[0], 0, 0});

        while (!pq.empty()) {
            auto [cost, time, u] = pq.top();
            pq.pop();

            if (cost != dp[time][u]) {
                continue;
            }

            if (u == n - 1) {
                return cost;
            }
            for (auto [v, travelTime] : adj[u]) {
                int newTime = time + travelTime;

                if (newTime > maxTime) {
                    continue;
                }
                int newCost = cost + passingFees[v];
                if (newCost < dp[newTime][v]) {
                    dp[newTime][v] = newCost;
                    pq.push({newCost, newTime, v});
                }
            }
        }
        return -1;
    }
};