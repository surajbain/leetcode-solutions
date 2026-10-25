class Solution {
    class DSU {
        vector<int> parent, sz;

    public:
        DSU(int n) {
            parent.resize(n);
            sz.assign(n, 1);
            iota(parent.begin(), parent.end(), 0);
        }

        int find(int x) {
            if (parent[x] != x) {
                parent[x] = find(parent[x]);
            }
            return parent[x];
        }

        bool unite(int a, int b) {
            a = find(a);
            b = find(b);

            if (a == b) {
                return false;
            }

            if (sz[a] < sz[b]) {
                swap(a, b);
            }

            parent[b] = a;
            sz[a] += sz[b];
            return true;
        }
    };

    int kruskal(int n, vector<vector<int>>& edges,
                int skip, int force) {
        DSU dsu(n);
        int weight = 0;
        int used = 0;
        if (force != -1) {
            auto& e = edges[force];

            if (dsu.unite(e[0], e[1])) {
                weight += e[2];
                used++;
            } else {
                return INT_MAX;
            }
        }

        for (int i = 0; i < edges.size(); i++) {
            if (i == skip || i == force) {
                continue;
            }

            auto& e = edges[i];

            if (dsu.unite(e[0], e[1])) {
                weight += e[2];
                used++;
            }
        }
        return used == n - 1 ? weight : INT_MAX;
    }

public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(
        int n, vector<vector<int>>& edges) {

        int m = edges.size();
        vector<vector<int>> indexedEdges;

        for (int i = 0; i < m; i++) {
            indexedEdges.push_back({
                edges[i][0],
                edges[i][1],
                edges[i][2],
                i
            });
        }

        sort(indexedEdges.begin(), indexedEdges.end(),
             [](const auto& a, const auto& b) {
                 return a[2] < b[2];
             });
        vector<vector<int>> sortedEdges;

        for (auto& e : indexedEdges) {
            sortedEdges.push_back({e[0], e[1], e[2]});
        }

        int mstWeight = kruskal(n, sortedEdges, -1, -1);

        vector<int> critical;
        vector<int> pseudoCritical;

        for (int i = 0; i < m; i++) {
            int withoutEdge = kruskal(n, sortedEdges, i, -1);

            if (withoutEdge > mstWeight) {
                critical.push_back(indexedEdges[i][3]);
            } else {
                int withEdge = kruskal(n, sortedEdges, -1, i);

                if (withEdge == mstWeight) {
                    pseudoCritical.push_back(indexedEdges[i][3]);
                }
            }
        }

        return {critical, pseudoCritical};
    }
};