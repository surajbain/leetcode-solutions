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
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
         int n = edges.size();

        vector<int> parentNode(n + 1, 0);
        vector<int> candidate1, candidate2;

        for (auto& e : edges) {
            int u = e[0], v = e[1];

            if (parentNode[v] == 0) {
                parentNode[v] = u;
            } else {
                candidate1 = {parentNode[v], v};
                candidate2 = {u, v};
                break;
            }
        }

        parent.resize(n + 1);
        for (int i = 1; i <= n; i++)
            parent[i] = i;
        for (auto& e : edges) {
            if (!candidate2.empty() &&
                e[0] == candidate2[0] &&
                e[1] == candidate2[1])
                continue;

            if (!unite(e[0], e[1])) {
                if (candidate1.empty())
                    return e;

                return candidate1;
            }
        }
        return candidate2;
    }
};