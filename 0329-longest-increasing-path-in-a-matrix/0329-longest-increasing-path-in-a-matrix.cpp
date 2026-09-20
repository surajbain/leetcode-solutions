class Solution {
public:
    int m, n;
    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& dp, int r, int c) {

        if (dp[r][c] != 0) {
            return dp[r][c];
        }
        dp[r][c] = 1;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1 };

        for (int k = 0; k < 4; k++ ) {
            int nr = r + dr[k];
            int nc = c+ dc[k];

            if (nr < 0 || nr >= m || nc < 0 || nc>=n) {
                continue;
            }

            if (matrix[nr][nc] > matrix[r][c] ) {
                dp[r][c] = max (
                    dp[r][c], 1 + dfs(matrix, dp, nr, nc) 
                );
            }
        }
            return dp[r][c];
    }


    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));
        int answer = 0;

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                answer = max (answer, dfs(matrix, dp, r, c));
            }
        }
        return answer;
    }
};