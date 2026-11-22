class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
          if (matrix.empty() || matrix[0].empty()) return false;
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        int row = 0;
        int col = cols - 1;
        
        while (row < rows && col >= 0) {
            int val = matrix[row][col];
            if (val == target) {
                return true;
            } else if (val > target) {
                col--; 
            } else {
                row++; 
            }
        }
        
        return false;
    }
};