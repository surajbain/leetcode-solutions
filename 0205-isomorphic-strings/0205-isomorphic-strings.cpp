class Solution {
public:
    bool isIsomorphic(string s, string t) {

        if (s.length() != t.length()) {
            return false;
        }
        unordered_map<char, char> sToT;
        unordered_map<char, char> tToS;

        for (int i = 0; i < s.length(); i++) {
            char a = s[i];
            char b = t[i];

            if (sToT.count(a) && sToT[a] != b) {
                return false;
            }
            if (tToS.count(b) && tToS[b] != a) {
                return false;
            }
            sToT[a] = b;
            tToS[b] = a;
        }
        return true;
    }
};