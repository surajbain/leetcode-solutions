class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {

        int n = patience.size();
        vector<vector<int>> adj(n);

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> dist(n, -1);
        queue<int> q;

        q.push(0);
        dist[0] = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int neighbor : adj[node]) {
                if (dist[neighbor] == -1) {
                    dist[neighbor] = dist[node] + 1;
                    q.push(neighbor);
                }
            }
        }

        int answer = 0;

        for (int i = 1; i < n; i++) {

            int roundTrip = 2 * dist[i];
            int lastSend = ((roundTrip - 1) / patience[i])* patience[i];
            int lastReply = lastSend + roundTrip;
            answer = max(answer, lastReply + 1);
        }

        return answer;
    }
};