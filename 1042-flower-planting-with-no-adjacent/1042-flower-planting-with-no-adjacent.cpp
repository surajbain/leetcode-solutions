class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> graph(n+1);

        for (auto &path : paths) {
            int u = path[0];
            int v = path[1];

            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        vector<int> flower(n+1, 0);

        for (int garden = 1; garden <= n; garden++) {
            bool used[5] = {};

            for (int neighbor: graph[garden])  {
                used[flower[neighbor]] = true;
            }

            for (int f= 1; f <= 4; f++) {
                if (!used[f]) {
                    flower[garden] = f;
                    break;
                }
            }
        }
        return vector<int>(flower.begin() + 1, flower.end());
    }
};