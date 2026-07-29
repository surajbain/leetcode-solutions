class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n= grid.size();
        vector<int> a(n);

        for (int i = 0; i<n; i++) {
            int lastOne = -1;
            for (int j = n - 1; j >= 0; j--) {
                if (grid[i][j] == 1) {
                    lastOne = j;
            
                break;
                }
            }
            a[i] = n - lastOne - 1;
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            int need = n-i-1;

            int j = i;
            while (j < n && a[j] < need)
            j++;

            if (j == n)
            return -1;

            while (j > i) {
                swap(a[j], a[j - 1]);
                ans ++;
                j--;
            }
        }
        return ans;
    }
};