class Solution {
public:
string ans;
    unordered_set<string> visited;

    void dfs(string node, int k) {
        for (char c = '0'; c < '0' + k; c++) {
            string next = node + c;

            if (!visited.count(next)) {
                visited.insert(next);
                dfs(next.substr(1), k);
                ans += c;
            }
        }
    }
    string crackSafe(int n, int k) {
        string start(n - 1, '0');
        dfs(start, k);
        ans += start;
        return ans;
    }
};