class Solution {
public:
    unordered_map<int, vector<int>> adj;
    vector<vector<int>> ans;

    void dfs(int node) {
        while (!adj[node].empty()) {
            int next = adj[node].back();
            adj[node].pop_back();

            dfs(next);

            ans.push_back({node, next});
        }
    }

    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, int> in, out;

        for (auto &p : pairs) {
            int u = p[0];
            int v = p[1];

            adj[u].push_back(v);
            out[u]++;
            in[v]++;
        }

        int start = pairs[0][0];

        for (auto &p : pairs) {
            int node = p[0];

            if (out[node] - in[node] == 1) {
                start = node;
                break;
            }
        }

        dfs(start);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};