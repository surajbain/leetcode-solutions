class Solution {
public:

int value(vector<int>& v) {
    int ans = 0;

    for (int x: v) {
        int bits = 0, t= x;

        while (t) {
            bits++;
            t >>=1;
        }
        ans = (ans << bits) | x;
    }
    return ans;
}
    int maxGoodNumber(vector<int>& nums) {
        sort (nums.begin(), nums.end());

        int ans = 0;

        do {
            ans = max(ans, value(nums));
        } while (next_permutation(nums.begin(), nums.end()));

        return ans;
    }
};