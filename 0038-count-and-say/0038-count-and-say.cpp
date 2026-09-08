class Solution {
public:
    string countAndSay(int n) {

        string result = "1";
        for (int term = 2; term <= n; term++) {

            string next = "";
            int i = 0;

            while (i < result.length()) {
                int count = 1;
                while (i + 1 < result.length() &&
                       result[i] == result[i + 1]) {
                    count++;
                    i++;
                }
                next += to_string(count);
                next += result[i];
                i++;
            }
            result = next;
        }
        return result;
    }
};