class Solution {
public:
    vector<int> parent, sz;

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b) return;

        if (sz[a] < sz[b]) {
            swap(a, b);
        }

        parent[b] = a;
        sz[a] += sz[b];
    }

    vector<bool> friendRequests( int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
        parent.resize(n);
        sz.assign(n, 1);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        vector<bool> ans;

        for (auto& req : requests) {
            int u = find(req[0]);
            int v = find(req[1]);
            if (u == v) {
                ans.push_back(true);
                continue;
            }

            bool valid = true;
            for (auto& r : restrictions) {
                int x = find(r[0]);
                int y = find(r[1]);

                if ((u == x && v == y) ||
                    (u == y && v == x)) {
                    valid = false;
                    break;
                }
            }

            if (valid) {
                unite(u, v);
                ans.push_back(true);
            } 
            else {
                ans.push_back(false);
            }
        }

        return ans;
    }
};