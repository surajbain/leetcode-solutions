class Solution {
public:
    const long long INF = LLONG_MAX / 4;

    vector<long long> dijkstra( int src, vector<vector<pair<int, int>>>& adj) { 
        int n = adj.size();
        vector<long long> dist(n, INF);

        priority_queue<
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<pair<long long, int>>
        > pq;

        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            auto [d, node] = pq.top();
            pq.pop();

            if (d > dist[node]) continue;

            for (auto [next, weight] : adj[node]) {
                long long newDist = d + weight;

                if (newDist < dist[next]) {
                    dist[next] = newDist;
                    pq.push({newDist, next});
                }
            }
        }

        return dist;
    }

    long long minimumWeight(
        int n,
        vector<vector<int>>& edges,
        int src1,
        int src2,
        int dest
    ) {
        vector<vector<pair<int, int>>> adj(n), rev(n);

        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];

            adj[u].push_back({v, w});
            rev[v].push_back({u, w});
        }

        vector<long long> dist1 = dijkstra(src1, adj);
        vector<long long> dist2 = dijkstra(src2, adj);
        vector<long long> dist3 = dijkstra(dest, rev);

        long long ans = INF;

        for (int i = 0; i < n; i++) {
            if (dist1[i] == INF ||
                dist2[i] == INF ||
                dist3[i] == INF) {
                continue;
            }

            ans = min(ans, dist1[i] + dist2[i] + dist3[i]);
        }

        return ans == INF ? -1 : ans;
    }
};