class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {

        vector<vector<int>> adj(n + 1);

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> dist1(n + 1, INT_MAX);
        vector<int> dist2(n + 1, INT_MAX);

        queue<pair<int, int>> q;

        dist1[1] = 0;
        q.push({1, 0});
        while (!q.empty()) {
            auto [node, d] = q.front();
            q.pop();

            for (int neighbor : adj[node]) {
                int nd = d + 1;

                if (nd < dist1[neighbor]) {
                    dist1[neighbor] = nd;
                    q.push({neighbor, nd});
                }
                else if (nd > dist1[neighbor] &&
                         nd < dist2[neighbor]) {
                    dist2[neighbor] = nd;
                    q.push({neighbor, nd});
                }
            }
        }
        int steps = dist2[n];
        int totalTime = 0;

        for (int i = 0; i < steps; i++) {
            if ((totalTime / change) % 2 == 1) {
                totalTime = ((totalTime / change) + 1) * change;
            }
            totalTime += time;
        }

        return totalTime;
    }
};