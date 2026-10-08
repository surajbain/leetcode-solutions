class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges,
                       int maxMoves, int n) {

        vector<vector<pair<int, int>>> graph(n);

        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];
            int cnt = e[2];

            graph[u].push_back({v, cnt});
            graph[v].push_back({u, cnt});
        }

        const long long INF = 1e18;

        vector<long long> dist(n, INF);

        priority_queue<
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<pair<long long, int>>
        > pq;

        dist[0] = 0;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if (d != dist[u])
                continue;

            for (auto [v, cnt] : graph[u]) {

                long long newDist = d + cnt + 1;

                if (newDist < dist[v]) {
                    dist[v] = newDist;
                    pq.push({newDist, v});
                }
            }
        }

        long long answer = 0;
        for (int i = 0; i < n; i++) {
            if (dist[i] <= maxMoves)
                answer++;
        }
        for (auto& e : edges) {

            int u = e[0];
            int v = e[1];
            int cnt = e[2];

            long long fromU = 0;
            long long fromV = 0;

            if (dist[u] <= maxMoves)
                fromU = maxMoves - dist[u];

            if (dist[v] <= maxMoves)
                fromV = maxMoves - dist[v];

            answer += min(
                (long long)cnt,
                fromU + fromV
            );
        }

        return (int)answer;
    }
};