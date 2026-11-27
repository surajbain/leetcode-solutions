class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        int ans = INT_MIN;
        
        for (int left = 0; left < n; left++) {
            vector<int> rowSum(m, 0);
            for (int right = left; right < n; right++) {
                for (int r = 0; r < m; r++) {
                    rowSum[r] += matrix[r][right];
                }
                
                set<int> prefix;
                prefix.insert(0);
                int curr = 0;
                for (int x : rowSum) {
                    curr += x;
                    auto it = prefix.lower_bound(curr - k);
                    if (it != prefix.end()) {
                        ans = max(ans, curr - *it);
                    }
                    prefix.insert(curr);
                }
            }
        }
        
        return ans;
    }
};
