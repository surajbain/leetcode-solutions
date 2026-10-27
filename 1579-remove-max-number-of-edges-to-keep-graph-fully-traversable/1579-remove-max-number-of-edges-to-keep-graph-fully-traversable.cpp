class Solution {
    class DSU {
    public:
        vector<int> parent, size;
        int components;

        DSU(int n) {
            parent.resize(n + 1);
            size.assign(n + 1, 1);
            components = n;

            for (int i = 1; i <= n; i++) {
                parent[i] = i;
            }
        }

        int find(int x) {
            if (parent[x] == x) {
                return x;
            }

            return parent[x] = find(parent[x]);
        }

        bool unite(int u, int v) {
            u = find(u);
            v = find(v);

            if (u == v) {
                return false;
            }

            if (size[u] < size[v]) {
                swap(u, v);
            }

            parent[v] = u;
            size[u] += size[v];
            components--;

            return true;
        }
    };

public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DSU alice(n), bob(n);
        int removed = 0;
        for (const auto& edge : edges) {
            int type = edge[0];
            int u = edge[1];
            int v = edge[2];

            if (type == 3) {
                bool usedAlice = alice.unite(u, v);
                bool usedBob = bob.unite(u, v);

                if (!usedAlice && !usedBob) {
                    removed++;
                }
            }
        }
        for (const auto& edge : edges) {
            if (edge[0] == 1) {
                if (!alice.unite(edge[1], edge[2])) {
                    removed++;
                }
            }
        }
        for (const auto& edge : edges) {
            if (edge[0] == 2) {
                if (!bob.unite(edge[1], edge[2])) {
                    removed++;
                }
            }
        }
        if (alice.components != 1 || bob.components != 1) {
            return -1;
        }

        return removed;
    }
};