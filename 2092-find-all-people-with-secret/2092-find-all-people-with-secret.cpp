class Solution {
public:
    vector<int> parent;

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a != b) {
            parent[b] = a;
        }
    }

    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {

        parent.resize(n);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        unite(0, firstPerson);
        sort(meetings.begin(), meetings.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[2] < b[2];
             });

        int m = meetings.size();
        int i = 0;

        while (i < m) {
            int currentTime = meetings[i][2];
            int j = i;
            while (j < m && meetings[j][2] == currentTime) {
                unite(meetings[j][0], meetings[j][1]);
                j++;
            }
            for (int k = i; k < j; k++) {
                int x = meetings[k][0];
                int y = meetings[k][1];

                if (find(x) != find(0)) {
                    parent[x] = x;
                }

                if (find(y) != find(0)) {
                    parent[y] = y;
                }
            }

            i = j;
        }

        vector<int> ans;

        for (int person = 0; person < n; person++) {
            if (find(person) == find(0)) {
                ans.push_back(person);
            }
        }

        return ans;
    }
};