class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        

        unordered_map<char, int> lastIndex;

        int left = 0;
        int maxLength = 0;

        for (int right = 0; right < s.length(); right++) {

            char current = s[right];

            if (lastIndex.find(current) != lastIndex.end() &&
                lastIndex[current] >= left) {

                left = lastIndex[current] + 1;
            }

            lastIndex[current] = right;

            int currentLength = right - left + 1;

            maxLength = max(maxLength, currentLength);
        }

        return maxLength;
        
    }
};