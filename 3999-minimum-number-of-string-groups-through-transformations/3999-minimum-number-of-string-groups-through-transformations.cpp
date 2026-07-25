class Solution {
public:

    int minRotation(string &s){
        int n = s.size();

        if(n == 0)
            return 0;

        string t = s + s;

        int i = 0; // first candidate
        int j = 1; // second candidate
        int k = 0; // matched length

        while(i < n && j < n && k < n){
            if(t[i + k] == t[j + k]){
                k++;
                continue;
            }

            if(t[i + k] > t[j + k]){   // i is worse than j
                i = i + k + 1;
            }
            else{                      // j is worse than i
                j = j + k + 1;
            }

            if(i == j){
                j++;
            }

            k = 0;
        }

        return min(i, j);
    }

    string getMinRotation(string &s){
        if(s.empty()){
            return "";
        }

        int p = minRotation(s);
        return s.substr(p) + s.substr(0, p);
    }

    int minimumGroups(vector<string>& words) {
        unordered_set<string> st;

        for(string &word : words){
            string even = "", odd = "";

            for(int i = 0; i < word.size(); i++){
                if(i % 2 == 0){
                    even += word[i];
                }
                else{
                    odd += word[i];
                }
            }

            even = getMinRotation(even);
            odd = getMinRotation(odd);

            st.insert(even + "#" + odd);
        }

        return st.size();
    }
};
