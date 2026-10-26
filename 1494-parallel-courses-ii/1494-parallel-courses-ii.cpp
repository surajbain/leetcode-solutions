class Solution {
public:
    int minNumberOfSemesters(int n, vector<vector<int>>& relations, int k) {
        vector<int> prereq(n, 0);
        for (auto& r : relations) {
            int prev = r[0] - 1;
            int next = r[1] - 1;
            prereq[next] |= (1 << prev);
        }

        int totalMasks = 1 << n;
        vector<int> dp(totalMasks, INT_MAX);
        dp[0] = 0;

        for (int mask = 0; mask < totalMasks; mask++) {
            if (dp[mask] == INT_MAX) {
                continue;
            }

            int available = 0;
            for (int course = 0; course < n; course++) {
                if (mask & (1 << course)) {
                    continue;
                }

                if ((prereq[course] & mask) == prereq[course]) {
                    available |= (1 << course);
                }
            }

            if (available == 0) {
                continue;
            }
            if (__builtin_popcount((unsigned)available) <= k) {
                int nextMask = mask | available;
                dp[nextMask] = min(dp[nextMask], dp[mask] + 1);
            } else {
                for (int subset = available; subset > 0;
                     subset = (subset - 1) & available) {

                    if (__builtin_popcount((unsigned)subset) == k) {
                        int nextMask = mask | subset;
                        dp[nextMask] = min(dp[nextMask], dp[mask] + 1);
                    }
                }
            }
        }

        return dp[totalMasks - 1];
    }
};