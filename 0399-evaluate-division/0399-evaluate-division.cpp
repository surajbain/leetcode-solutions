class Solution {
public:
 unordered_map<string, vector<pair<string, double>>> graph;

    double dfs(string current, string target,
               unordered_set<string>& visited,
               double product) {

        if (current == target)
            return product;

        visited.insert(current);

        for (auto& [next, weight] : graph[current]) {
            if (visited.count(next))
                continue;

            double result = dfs(next, target, visited, product * weight);

            if (result != -1.0)
                return result;
            }
               return -1.0;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
         for (int i = 0; i < equations.size(); i++) {
            string a = equations[i][0];
            string b = equations[i][1];
            double value = values[i];
            graph[a].push_back({b, value});
            graph[b].push_back({a, 1.0 / value});
        }

        vector<double> answer;

        for (auto& query : queries) {
            string start = query[0];
            string target = query[1];

            if (!graph.count(start) || !graph.count(target)) {
                answer.push_back(-1.0);
                continue;
            }

            unordered_set<string> visited;
            answer.push_back(
                dfs(start, target, visited, 1.0)
            );
        }

        return answer;
    }
};