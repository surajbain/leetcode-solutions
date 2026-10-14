class Solution {
public:
    vector<string> watchedVideosByFriends( vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level ) {
        int n = friends.size();
        vector<bool> visited(n, false);
        queue<int> q;

        q.push(id);
        visited[id] = true;
        int currentLevel = 0;
        while (!q.empty() && currentLevel < level) {
            int size = q.size();

            while (size--) {
                int person = q.front();
                q.pop();
                for (int friendId : friends[person]) {
                    if (!visited[friendId]) {
                        visited[friendId] = true;
                        q.push(friendId);
                    }
                }
            }

            currentLevel++;
        }
        unordered_map<string, int> frequency;
        while (!q.empty()) {
            int person = q.front();
            q.pop();

            for (string& video : watchedVideos[person]) {
                frequency[video]++;
            }
        }
        vector<string> answer;
        for (auto& [video, count] : frequency) {
            answer.push_back(video);
        }

        sort(answer.begin(), answer.end(),
             [&](const string& a, const string& b) {
                 if (frequency[a] != frequency[b]) {
                     return frequency[a] < frequency[b];
                 }

                 return a < b;
             });

        return answer;
    }
};