class Solution {
public:
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> ans(m, vector<int>(n, 0));
        vector<int> rowMax(m, 0);
        vector<int> colMax(n, 0);

        map<int, vector<pair<int, int>>> groups;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                groups[matrix[i][j]].push_back({i, j});
            }
        }

        for (auto& [value, cells] : groups) {
            int k = cells.size();

            vector<int> parent(m + n);
            iota(parent.begin(), parent.end(), 0);

            function<int(int)> find = [&](int x) {
                if (parent[x] != x) {
                    parent[x] = find(parent[x]);
                }
                return parent[x];
            };

            auto unite = [&](int a, int b) {
                a = find(a);
                b = find(b);

                if (a != b) {
                    parent[a] = b;
                }
            };
            for (auto [r, c] : cells) {
                unite(r, m + c);
            }

            unordered_map<int, int> componentRank;
            for (auto [r, c] : cells) {
                int root = find(r);
                int rank = max(rowMax[r], colMax[c]) + 1;

                componentRank[root] =
                    max(componentRank[root], rank);
            }
            for (auto [r, c] : cells) {
                int root = find(r);
                int rank = componentRank[root];

                ans[r][c] = rank;
            }

            for (auto [r, c] : cells) {
                rowMax[r] = max(rowMax[r], ans[r][c]);
                colMax[c] = max(colMax[c], ans[r][c]);
            }
        }

        return ans;
    }
};