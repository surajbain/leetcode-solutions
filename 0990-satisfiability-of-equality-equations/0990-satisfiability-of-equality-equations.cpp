class Solution {
public:
    vector<int> parent;
    int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a != b)
            parent[b] = a;
    }

    bool equationsPossible(vector<string>& equations) {

        parent.resize(26);
        for (int i = 0; i < 26; i++)
            parent[i] = i;
        for (string& eq : equations) {

            if (eq[1] == '=') {
                int a = eq[0] - 'a';
                int b = eq[3] - 'a';

                unite(a, b);
            }
        }
        for (string& eq : equations) {
            if (eq[1] == '!') {
                int a = eq[0] - 'a';
                int b = eq[3] - 'a';

                if (find(a) == find(b))
                    return false;
            }
        }

        return true;
    }
};