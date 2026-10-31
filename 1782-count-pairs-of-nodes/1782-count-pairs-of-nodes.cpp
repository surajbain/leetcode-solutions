class Solution {
public:
    vector<int> countPairs(
        int n,
        vector<vector<int>>& edges,
        vector<int>& queries
    ) {
        vector<int> degree(n + 1, 0);

        unordered_map<long long, int> common;

        auto getKey = [&](int u, int v) -> long long {
            if (u > v) swap(u, v);
            return 1LL * u * (n + 1) + v;
        };

        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            degree[u]++;
            degree[v]++;

            common[getKey(u, v)]++;
        }

        vector<int> sortedDegree;
        for (int i = 1; i <= n; i++) {
            sortedDegree.push_back(degree[i]);
        }

        sort(sortedDegree.begin(), sortedDegree.end());

        vector<int> answer;
        answer.reserve(queries.size());

        for (int q : queries) {
            int left = 0;
            int right = n - 1;
            int count = 0;
            while (left < right) {
                if (sortedDegree[left] + sortedDegree[right] > q) {
                    count += right - left;
                    right--;
                } else {
                    left++;
                }
            }
            for (const auto& [key, c] : common) {
                int u = key / (n + 1);
                int v = key % (n + 1);

                int sum = degree[u] + degree[v];

                if (sum > q && sum - c <= q) {
                    count--;
                }
            }

            answer.push_back(count);
        }

        return answer;
    }
};