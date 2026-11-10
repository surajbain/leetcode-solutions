class Solution {
public:
    vector<string> findAllRecipes( vector<string>& recipes, vector<vector<string>>& ingredients,  vector<string>& supplies) {
        unordered_map<string, vector<string>> adj;
        unordered_map<string, int> indegree;
        for (int i = 0; i < recipes.size(); i++) {
            indegree[recipes[i]] = ingredients[i].size();

            for (string& ingredient : ingredients[i]) {
                adj[ingredient].push_back(recipes[i]);
            }
        }
        queue<string> q;

        for (string& supply : supplies) {
            q.push(supply);
        }

        vector<string> ans;

        while (!q.empty()) {
            string item = q.front();
            q.pop();

            for (string& recipe : adj[item]) {
                indegree[recipe]--;

                if (indegree[recipe] == 0) {
                    ans.push_back(recipe);
                    q.push(recipe);
                }
            }
        }

        return ans;
    }
};