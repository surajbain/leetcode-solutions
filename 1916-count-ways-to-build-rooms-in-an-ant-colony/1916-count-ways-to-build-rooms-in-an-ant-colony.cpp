class Solution {
private:
    static constexpr long long MOD = 1'000'000'007LL;

    vector<vector<int>> children;
    vector<long long> fact, invFact, ways;
    vector<int> subtreeSize;

    long long modPow(long long base, long long exp) {
        long long result = 1;

        while (exp > 0) {
            if (exp & 1) {
                result = result * base % MOD;
            }

            base = base * base % MOD;
            exp >>= 1;
        }

        return result;
    }

    void dfs(int u) {
        subtreeSize[u] = 1;
        ways[u] = 1;

        for (int v : children[u]) {
            dfs(v);

            subtreeSize[u] += subtreeSize[v];
            ways[u] = ways[u] * ways[v] % MOD;
            ways[u] = ways[u] * invFact[subtreeSize[v]] % MOD;
        }

        ways[u] = ways[u] * fact[subtreeSize[u] - 1] % MOD;
    }

public:
    int waysToBuildRooms(vector<int>& prevRoom) {
        int n = prevRoom.size();

        children.assign(n, {});
        for (int i = 1; i < n; i++) {
            children[prevRoom[i]].push_back(i);
        }

        fact.assign(n + 1, 1);
        invFact.assign(n + 1, 1);

        for (int i = 1; i <= n; i++) {
            fact[i] = fact[i - 1] * i % MOD;
        }

        invFact[n] = modPow(fact[n], MOD - 2);

        for (int i = n; i >= 1; i--) {
            invFact[i - 1] = invFact[i] * i % MOD;
        }

        subtreeSize.assign(n, 0);
        ways.assign(n, 1);

        dfs(0);

        return ways[0];
    }
};