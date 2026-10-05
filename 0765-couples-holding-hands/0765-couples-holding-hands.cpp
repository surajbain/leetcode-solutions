class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
         int n = row.size();
        int swaps = 0;

        for (int i = 0; i < n; i += 2) {
            int partner = row[i] ^ 1;

            if (row[i + 1] == partner)
                continue;

            for (int j = i + 2; j < n; j++) {
                if (row[j] == partner) {
                    swap(row[i + 1], row[j]);
                    swaps++;
                    break;
                }
            }
        }
        return swaps;
    }
};