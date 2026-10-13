class Solution {
public:
    vector<int> topoSort(vector<vector<int>>& graph, vector<int>& indegree) {
        queue<int> q;
        vector<int> order;

        for (int i = 0; i < graph.size(); i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            order.push_back(u);

            for (int v : graph[u]) {
                if (--indegree[v] == 0)
                    q.push(v);
            }
        }

        if (order.size() != graph.size())
            return {};

        return order;
    }

    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        for (int i = 0; i < n; i++) {
            if (group[i] == -1)
                group[i] = m++;
        }

        vector<vector<int>> itemGraph(n);
        vector<vector<int>> groupGraph(m);

        vector<int> itemIndegree(n, 0);
        vector<int> groupIndegree(m, 0);

        for (int v = 0; v < n; v++) {
            for (int u : beforeItems[v]) {
                itemGraph[u].push_back(v);
                itemIndegree[v]++;

                if (group[u] != group[v]) {
                    groupGraph[group[u]].push_back(group[v]);
                    groupIndegree[group[v]]++;
                }
            }
        }
        vector<int> itemOrder = topoSort(itemGraph, itemIndegree);
        vector<int> groupOrder = topoSort(groupGraph, groupIndegree);

        if (itemOrder.empty() || groupOrder.empty())
            return {};
        vector<vector<int>> groupedItems(m);

        for (int item : itemOrder)
            groupedItems[group[item]].push_back(item);
        vector<int> answer;

        for (int g : groupOrder) {
            for (int item : groupedItems[g])
                answer.push_back(item);
        }

        return answer;
    }
};