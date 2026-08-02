class Solution {
public:
    int minFlips(string s) {
        int n = s.size();

        if (n % 2 == 0) {
            int diff1 = 0, diff2 = 0;
            for (int i = 0; i < n; i++) {
                char c1 = (i % 2) ? '1' : '0';
                char c2 = (i % 2) ? '0' : '1';

                if (s[i] != c1) diff1++;
                if (s[i] != c2) diff2++;
            }
            return min(diff1, diff2);
        }

        string t = s + s;

        int diff1 = 0, diff2 = 0;
        int ans = INT_MAX;

        int left = 0;

        for (int right = 0; right < 2 * n; right++) {

            char c1 = (right % 2) ? '1' : '0';
            char c2 = (right % 2) ? '0' : '1';

            if (t[right] != c1) diff1++;
            if (t[right] != c2) diff2++;

            if (right - left + 1 > n) {
                c1 = (left % 2) ? '1' : '0';
                c2 = (left % 2) ? '0' : '1';

                if (t[left] != c1) diff1--;
                if (t[left] != c2) diff2--;

                left++;
            }

            if (right - left + 1 == n) {
                ans = min(ans, min(diff1, diff2));
            }
        }

        return ans;
    }
};