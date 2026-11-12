class Solution {
public:
    int maximumScore(vector<int>& scores, vector<vector<int>>& edges) {
        int n = scores.size();

        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);\
            adj[v].push_back(u);
        }
        for (int i = 0; i < n; i++) {
            sort(adj[i].begin(), adj[i].end(),
                 [&](int a, int b) {
                     return scores[a] > scores[b];
                 });
            if (adj[i].size() > 3) {
                adj[i].resize(3);
            }
        }

        int ans = -1;
        for (auto& e : edges) {
            int b = e[0];
            int c = e[1];

            for (int a : adj[b]) {
                for (int d : adj[c]) {
                    if (a == c || d == b || a == d) {
                        continue;
                    }

                    int total = scores[a] + scores[b]
                              + scores[c] + scores[d];

                    ans = max(ans, total);
                }
            }
        }

        return ans;
    }
};