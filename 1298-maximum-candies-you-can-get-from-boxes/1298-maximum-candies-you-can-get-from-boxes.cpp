class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
     int n = status.size();

        vector<bool> found(n, false);
        vector<bool> opened(n, false);
        queue<int> q;

        for (int box : initialBoxes) {
            found[box] = true;
            q.push(box);
        }
        int answer = 0;
        while (!q.empty()) {
            int box = q.front();
            q.pop();

            if (opened[box] || !status[box])
                continue;

            opened[box] = true;
            answer += candies[box];
            for (int key : keys[box]) {
                status[key] = 1;
                if (found[key] && !opened[key]) {
                    q.push(key);
                }
            }
            for (int next : containedBoxes[box]) {
                if (!found[next]) {
                    found[next] = true;
                    q.push(next);
                }
            }
        }

        return answer;   
    }
};