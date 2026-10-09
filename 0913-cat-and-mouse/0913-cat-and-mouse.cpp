class Solution {
public:
    static const int DRAW = 0;
    static const int MOUSE = 1;
    static const int CAT = 2;

    struct State {
        int mouse;
        int cat;
        int turn;
    };

    int catMouseGame(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<vector<int>>> result(
            n, vector<vector<int>>(n, vector<int>(2, DRAW))
        );
        vector<vector<vector<int>>> degree(
            n, vector<vector<int>>(n, vector<int>(2, 0))
        );

        queue<State> q;
        for (int m = 0; m < n; m++) {
            for (int c = 0; c < n; c++) {

                degree[m][c][0] = graph[m].size();

                for (int next : graph[c]) {
                    if (next != 0)
                        degree[m][c][1]++;
                }
            }
        }
        for (int c = 1; c < n; c++) {
            result[0][c][0] = MOUSE;
            result[0][c][1] = MOUSE;

            q.push({0, c, 0});
            q.push({0, c, 1});
        }
        for (int i = 1; i < n; i++) {
            result[i][i][0] = CAT;
            result[i][i][1] = CAT;

            q.push({i, i, 0});
            q.push({i, i, 1});
        }

        while (!q.empty()) {
            auto [m, c, turn] = q.front();
            q.pop();

            int winner = result[m][c][turn];
            if (turn == 0) {
                for (int prevCat : graph[c]) {

                    if (prevCat == 0)
                        continue;
                    int pm = m;
                    int pc = prevCat;
                    int pturn = 1;

                    if (result[pm][pc][pturn] != DRAW)
                        continue;
                    if (winner == CAT) {
                        result[pm][pc][pturn] = CAT;
                        q.push({pm, pc, pturn});
                    } else {
                        degree[pm][pc][pturn]--;

                        if (degree[pm][pc][pturn] == 0) {
                            result[pm][pc][pturn] = MOUSE;
                            q.push({pm, pc, pturn});
                        }
                    }
                }
            } else {
                for (int prevMouse : graph[m]) {

                    int pm = prevMouse;
                    int pc = c;
                    int pturn = 0;
                    if (result[pm][pc][pturn] != DRAW)
                        continue;
                    if (winner == MOUSE) {
                        result[pm][pc][pturn] = MOUSE;
                        q.push({pm, pc, pturn});
                    } else {
                        degree[pm][pc][pturn]--;
                        if (degree[pm][pc][pturn] == 0) {
                            result[pm][pc][pturn] = CAT;
                            q.push({pm, pc, pturn});
                        }
                    }
                }
            }
        }
        return result[1][2][0];
    }
};