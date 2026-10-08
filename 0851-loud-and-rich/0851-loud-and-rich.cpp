class Solution {
public:
    vector<vector<int>> graph;
    vector<int> ans;

    int dfs(int person, vector<int>& quiet) {
        if (ans[person] != -1)
            return ans[person];

        ans[person] = person;

        for (int richer : graph[person]) {
            int candidate = dfs(richer, quiet);

            if (quiet[candidate] < quiet[ans[person]]) {
                ans[person] = candidate;
            }
        }

        return ans[person];
    }

    vector<int> loudAndRich(vector<vector<int>>& richer,
                            vector<int>& quiet) {
        int n = quiet.size();

        graph.resize(n);
        ans.assign(n, -1);

        for (auto& edge : richer) {
            int rich = edge[0];
            int poor = edge[1];

            graph[poor].push_back(rich);
        }
        for (int i = 0; i < n; i++) {
            dfs(i, quiet);
        }

        return ans;
    }
};