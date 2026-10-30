class DSU {
private:
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

    bool connected(int a, int b) {
        return find(a) == find(b);
    }
};

class Solution {
public:
    vector<bool> distanceLimitedPathsExist( int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        sort(edgeList.begin(), edgeList.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[2] < b[2];
             });

        int q = queries.size();

        vector<vector<int>> sortedQueries(q);

        for (int i = 0; i < q; i++) {
            sortedQueries[i] = {
                queries[i][0],
                queries[i][1],
                queries[i][2],
                i
            };
        }

        sort(sortedQueries.begin(), sortedQueries.end(), [](const vector<int>& a, const vector<int>& b) {
                 return a[2] < b[2];
             });

        DSU dsu(n);
        vector<bool> answer(q, false);

        int j = 0;

        for (const auto& query : sortedQueries) {
            int p = query[0];
            int destination = query[1];
            int limit = query[2];
            int originalIndex = query[3];

            while (j < edgeList.size() &&
                   edgeList[j][2] < limit) {

                dsu.unite(edgeList[j][0], edgeList[j][1]);
                j++;
            }

            answer[originalIndex] =
                dsu.connected(p, destination);
        }

        return answer;
    }
};