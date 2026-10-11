class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges
    ) {
        
        vector<vector<pair<int, int>>> graph(n);
        for (auto& edge : redEdges) {
            graph[edge[0]].push_back({edge[1], 0});
        }

        for (auto& edge : blueEdges) {
            graph[edge[0]].push_back({edge[1], 1});
        }

        const int INF = 1e9;

        vector<vector<int>> dist(n, vector<int>(2, INF));

        queue<pair<int, int>> q;

        dist[0][0] = 0;
        dist[0][1] = 0;

        q.push({0, 0});
        q.push({0, 1});

        while (!q.empty()) {
            auto [node, lastColor] = q.front();
            q.pop();

            for (auto [next, color] : graph[node]) {
                if (color == lastColor)
                    continue;

                if (dist[next][color] == INF) {

                    dist[next][color] =
                        dist[node][lastColor] + 1;

                    q.push({next, color});
                }
            }
        }

        vector<int> answer(n);

        for (int i = 0; i < n; i++) {

            int best = min(dist[i][0], dist[i][1]);

            answer[i] = (best == INF ? -1 : best);
        }

        return answer;
    }
};