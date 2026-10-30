class Solution {
public:
    int checkWays(vector<vector<int>>& pairs) {
        unordered_map<int, unordered_set<int>> adj;

        for (auto& p : pairs) {
            int x = p[0];
            int y = p[1];

            adj[x].insert(y);
            adj[y].insert(x);
        }

        int n = adj.size();
        int root = -1;

        for (auto& [node, neighbors] : adj) {
            if ((int)neighbors.size() == n - 1) {
                root = node;
                break;
            }
        }

        if (root == -1) {
            return 0;
        }

        int ans = 1;

        for (auto& [node, neighbors] : adj) {
            if (node == root) {
                continue;
            }

            int parent = -1;
            int parentDegree = INT_MAX;
            int degree = neighbors.size();

            for (int neighbor : neighbors) {
                int neighborDegree = adj[neighbor].size();

                if (neighborDegree >= degree &&
                    neighborDegree < parentDegree) {
                    parent = neighbor;
                    parentDegree = neighborDegree;
                }
            }

            if (parent == -1) {
                return 0;
            }
            for (int neighbor : neighbors) {
                if (neighbor == parent) {
                    continue;
                }

                if (!adj[parent].count(neighbor)) {
                    return 0;
                }
            }

            if (parentDegree == degree) {
                ans = 2;
            }
        }

        return ans;
    }
};