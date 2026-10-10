class Solution {
public:
    void dfs(int node, vector<vector<int>>& stones, vector<bool>& visited) {
        visited[node] = true;
        for (int i = 0; i < stones.size(); i++) {
            if (!visited[i] &&
                (stones[node][0] == stones[i][0] ||
                 stones[node][1] == stones[i][1])) {
                dfs(i, stones, visited);
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<bool> visited(n, false);
        int components = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                components++;
                dfs(i, stones, visited);
            }
        }
        return n - components;
    }
};