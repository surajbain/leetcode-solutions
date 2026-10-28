class Solution {
public:
    bool isPrintable(vector<vector<int>>& targetGrid) {
        int m = targetGrid.size();
        int n = targetGrid[0].size();

        const int COLORS = 61;

        vector<int> minRow(COLORS, m);
        vector<int> maxRow(COLORS, -1);
        vector<int> minCol(COLORS, n);
        vector<int> maxCol(COLORS, -1);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int color = targetGrid[i][j];

                minRow[color] = min(minRow[color], i);
                maxRow[color] = max(maxRow[color], i);
                minCol[color] = min(minCol[color], j);
                maxCol[color] = max(maxCol[color], j);
            }
        }

        vector<vector<bool>> graph(
            COLORS, vector<bool>(COLORS, false)
        );

        vector<int> indegree(COLORS, 0);
        vector<bool> present(COLORS, false);
        for (int color = 1; color < COLORS; color++) {
            if (maxRow[color] != -1) {
                present[color] = true;
            }
        }
        for (int color = 1; color < COLORS; color++) {
            if (!present[color]) {
                continue;
            }

            for (int i = minRow[color];
                 i <= maxRow[color]; i++) {

                for (int j = minCol[color];
                     j <= maxCol[color]; j++) {

                    int other = targetGrid[i][j];

                    if (other != color &&
                        !graph[color][other]) {

                        graph[color][other] = true;
                        indegree[other]++;
                    }
                }
            }
        }
        queue<int> q;
        int totalColors = 0;

        for (int color = 1; color < COLORS; color++) {
            if (present[color]) {
                totalColors++;

                if (indegree[color] == 0) {
                    q.push(color);
                }
            }
        }
        int processed = 0;
        while (!q.empty()) {
            int color = q.front();
            q.pop();
            processed++;

            for (int next = 1; next < COLORS; next++) {
                if (graph[color][next]) {
                    indegree[next]--;

                    if (indegree[next] == 0) {
                        q.push(next);
                    }
                }
            }
        }
        return processed == totalColors;
    }
};