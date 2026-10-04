class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
         vector<vector<pair<int,int>>> graph(n + 1);

        for (auto& t : times) {
            graph[t[0]].push_back({t[1], t[2]});
        }

        vector<int> dist(n + 1, INT_MAX);
        priority_queue<pair<int,int>,  vector<pair<int,int>>, greater<pair<int,int>>> pq;

        dist[k] = 0;
        pq.push({0, k});

        while (!pq.empty()) {
            auto [time, node] = pq.top();
            pq.pop();

            if (time > dist[node])
                continue;

            for (auto [next, weight] : graph[node]) {
                int newTime = time + weight;
                if (newTime < dist[next]) {
                    dist[next] = newTime;
                    pq.push({newTime, next});
                }
            }
        }
        int answer = 0;

        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX)
                return -1;

            answer = max(answer, dist[i]);
        }

        return answer;
    }
};