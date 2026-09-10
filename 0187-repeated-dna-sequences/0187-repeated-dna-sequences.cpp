class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {

        unordered_set<string> seen;
        unordered_set<string> repeated;

        for (int i = 0; i + 10 <= s.length(); i++) {

            string sequence = s.substr(i, 10);

            if (seen.count(sequence)) {
                repeated.insert(sequence);
            } else {
                seen.insert(sequence);
            }
        }

        return vector<string>(repeated.begin(), repeated.end());
    }
};