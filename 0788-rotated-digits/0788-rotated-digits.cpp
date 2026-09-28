class Solution {
public:
    int rotatedDigits(int n) {
        int ans = 0;

        for (int i = 1; i <= n; i++) {
            int x = i;
            bool valid = true;
            bool changed = false;

            while (x > 0) {
                int digit = x % 10;

                if ( digit == 3  || digit == 4 || digit == 7 ) {
                    valid = false;
                    break;

                }
                if (digit == 2 || digit == 5 || digit == 6 || digit == 9) {
                    changed = true;
                }
                x /= 10;
            }
            if (valid && changed )
            ans++;
        }
        return ans;
    }
};