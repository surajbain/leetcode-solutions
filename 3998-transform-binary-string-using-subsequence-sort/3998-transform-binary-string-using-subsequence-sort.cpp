class Solution {
    int count(string str, char value) {
        int cnt = 0;
        for (char c : str) {
            if (c == value)
                cnt++;
        }
        return cnt;
    }

public:
    vector<bool> transformStr(string s, vector<string>& strs) {
        int n = s.size();

        int zero_s = count(s, '0');
        int one_s = count(s, '1');

        vector<bool> res;

        for (string str : strs) {

            int zero_str = count(str, '0');
            int one_str = count(str, '1');

            int diff_0 = zero_s - zero_str;
            int diff_1 = one_s - one_str;

            // Step-1: Check availability
            if (diff_0 < 0 || diff_1 < 0) {
                res.push_back(false);
                continue;
            }

            // Step-2: Fill leftmost '?' with '0'
            for (int i = 0; i < n && diff_0 > 0; i++) {
                if (str[i] == '?') {
                    str[i] = '0';
                    diff_0--;
                }
            }

            // Step-3: Fill remaining '?' with '1'
            for (int i = 0; i < n && diff_1 > 0; i++) {
                if (str[i] == '?') {
                    str[i] = '1';
                    diff_1--;
                }
            }

            bool solved = true;
            int s_one_idx = 0;
            int str_one_idx = 0;

            for (int i = 0; i < n; i++) {
                if (s[i] == '1')
                    s_one_idx++;

                if (str[i] == '1')
                    str_one_idx++;

                if (str_one_idx > s_one_idx) {
                    solved = false;
                    break;
                }
            }

            res.push_back(solved);
        }

        return res;
    }
};