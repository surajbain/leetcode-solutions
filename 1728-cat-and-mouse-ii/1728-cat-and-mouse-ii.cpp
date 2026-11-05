class Solution {
public:
    bool canMouseWin(vector<string>& grid, int catJump, int mouseJump) {
        int r = grid.size();
        int c = grid[0].size();

        int n = r * c;
        int mouse = -1, cat = -1, food = -1;

        vector<vector<int>> moves(n);

        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};

        auto valid = [&](int x, int y) {
            return x >= 0 && x < r &&
                   y >= 0 && y < c &&
                   grid[x][y] != '#';
        };
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                int pos = i * c + j;

                if (grid[i][j] == 'M') mouse = pos;
                if (grid[i][j] == 'C') cat = pos;
                if (grid[i][j] == 'F') food = pos;
            }
        }
        vector<vector<int>> mouseMoves(n);
        vector<vector<int>> catMoves(n);

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (!valid(i, j)) continue;

                int pos = i * c + j;

                mouseMoves[pos].push_back(pos);
                catMoves[pos].push_back(pos);

                for (int d = 0; d < 4; d++) {
                    for (int k = 1; k <= max(mouseJump, catJump); k++) {
                        int x = i + dx[d] * k;
                        int y = j + dy[d] * k;

                        if (!valid(x, y)) break;

                        int next = x * c + y;

                        if (k <= mouseJump) {
                            mouseMoves[pos].push_back(next);
                        }

                        if (k <= catJump && next != food) {
                            catMoves[pos].push_back(next);
                        }
                    }
                }
            }
        }

        vector<vector<vector<int>>> result(
            n, vector<vector<int>>(n, vector<int>(2, 0))
        );

        vector<vector<vector<int>>> degree(
            n, vector<vector<int>>(n, vector<int>(2, 0))
        );

        queue<tuple<int, int, int>> q;
        for (int m = 0; m < n; m++) {
            for (int ct = 0; ct < n; ct++) {

                degree[m][ct][0] = mouseMoves[m].size();
                degree[m][ct][1] = catMoves[ct].size();

                for (int turn = 0; turn < 2; turn++) {

                    if (m == food) {
                        result[m][ct][turn] = 1;
                    }
                    else if (ct == food || m == ct) {
                        result[m][ct][turn] = 2;
                    }

                    if (result[m][ct][turn] != 0) {
                        q.push({m, ct, turn});
                    }
                }
            }
        }
        while (!q.empty()) {

            auto [m, ct, turn] = q.front();
            q.pop();

            int winner = result[m][ct][turn];

            if (turn == 0) {
                for (int prevCat : catMoves[ct]) {

                    if (prevCat == food) continue;

                    int pm = m;
                    int pc = prevCat;
                    int pt = 1;

                    if (result[pm][pc][pt] != 0) continue;
                    if (winner == 2) {
                        result[pm][pc][pt] = 2;
                        q.push({pm, pc, pt});
                    }
                    else {
                        degree[pm][pc][pt]--;

                        if (degree[pm][pc][pt] == 0) {
                            result[pm][pc][pt] = 1;
                            q.push({pm, pc, pt});
                        }
                    }
                }

            }
            else {
                for (int prevMouse : mouseMoves[m]) {

                    int pm = prevMouse;
                    int pc = ct;
                    int pt = 0;

                    if (result[pm][pc][pt] != 0) continue;
                    if (winner == 1) {
                        result[pm][pc][pt] = 1;
                        q.push({pm, pc, pt});
                    }
                    else {
                        degree[pm][pc][pt]--;

                        if (degree[pm][pc][pt] == 0) {
                            result[pm][pc][pt] = 2;
                            q.push({pm, pc, pt});
                        }
                    }
                }
            }
        }
        return result[mouse][cat][0] == 1;
    }
};