class Solution {
public:
    vector<int> parent;

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b)
            return false;

        parent[b] = a;
        return true;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        parent.resize(n + 1);
        for (int i = 1; i <= n; i++)
            parent[i] = i;

        for (auto& edge : edges) {
            if (!unite(edge[0], edge[1]))
                return edge;
        }

        return {};
    }
};