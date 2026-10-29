class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) { 
        vector<int> degree(n, 0);
        vector<vector<bool>> connected(
            n, vector<bool>(n, false)
        );
        for (const auto& road : roads) {
            int u = road[0];
            int v = road[1];

            degree[u]++;
            degree[v]++;

            connected[u][v] = true;
            connected[v][u] = true;
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int rank = degree[i] + degree[j];

                if (connected[i][j]) {
                    rank--;
                }

                ans = max(ans, rank);
            }
        }

        return ans;
    }
};