class Solution {
public:
    double ans = 0.0;

    void dfs(vector<vector<int>>& graph, int node, int parent, int t, int target, double probability) {

        int children = graph[node].size() - (parent != 0);
        if (t == 0 || children == 0) {
            if (node == target) {
                ans = probability;
            }
            return;
        }

        double nextProbability = probability / children;

        for (int next : graph[node]) {
            if (next == parent) {
                continue;
            }

            dfs(graph, next, node, t - 1, target, nextProbability);
        }
    }

    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {

        vector<vector<int>> graph(n + 1);

        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        dfs(graph, 1, 0, t, target, 1.0);

        return ans;
    }
};