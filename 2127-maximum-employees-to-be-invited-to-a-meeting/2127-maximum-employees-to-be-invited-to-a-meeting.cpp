class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();

        vector<int> indegree(n, 0);
        vector<int> depth(n, 1);
        for (int i = 0; i < n; i++) {
            indegree[favorite[i]]++;
        }
        queue<int> q;

        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            int next = favorite[node];

            depth[next] = max(depth[next], depth[node] + 1);

            indegree[next]--;

            if (indegree[next] == 0) {
                q.push(next);
            }
        }

        int longestCycle = 0;
        int twoCycleSum = 0;

        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++) {
            if (indegree[i] > 0 && !visited[i]) {
                int node = i;
                int cycleLength = 0;

                while (!visited[node]) {
                    visited[node] = true;
                    cycleLength++;
                    node = favorite[node];
                }

                if (cycleLength == 2) {
                    int a = i;
                    int b = favorite[i];

                    twoCycleSum += depth[a] + depth[b];
                } else {
                    longestCycle = max(longestCycle, cycleLength);
                }
            }
        }

        return max(longestCycle, twoCycleSum);
    }
};