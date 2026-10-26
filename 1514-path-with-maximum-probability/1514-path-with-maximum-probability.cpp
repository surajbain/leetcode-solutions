class Solution {
public:
    double maxProbability( int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node ) {
        vector<vector<pair<int, double>>> graph(n);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            double p = succProb[i];

            graph[u].push_back({v, p});
            graph[v].push_back({u, p});
        }

        vector<double> prob(n, 0.0);
        priority_queue<pair<double, int>> pq;

        prob[start_node] = 1.0;
        pq.push({1.0, start_node});

        while (!pq.empty()) {
            auto [currentProb, node] = pq.top();
            pq.pop();
            if (currentProb < prob[node]) {
                continue;
            }

            if (node == end_node) {
                return currentProb;
            }

            for (auto& [neighbor, edgeProb] : graph[node]) {
                double newProb = currentProb * edgeProb;

                if (newProb > prob[neighbor]) {
                    prob[neighbor] = newProb;
                    pq.push({newProb, neighbor});
                }
            }
        }

        return 0.0;
    }
};