class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);

        for ( auto &p : prerequisites) {
            int course = p[0];
            int prerequisite =p[1];

            graph[prerequisite].push_back(course);
            indegree[course]++;
        }
        queue<int> q;

        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        vector<int> answer;

        while (!q.empty()) {
            int course = q.front();
            q.pop();

            answer.push_back(course);

            for (int next : graph[course]) {
                indegree[next]--;

                if (indegree[next] == 0) {
                    q.push(next);
                }
            }
        }
        if (answer.size() != numCourses) {
            return {};
        }
        return answer;
    }
};