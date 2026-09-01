class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();
        int sr = 0, sc = 0;
        vector<pair<int,int>> litter;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                }
                if(classroom[i][j] == 'L') {
                    litter.push_back({i, j});
                }
            }
        }
        int total = litter.size();
        if(total == 0)
            return 0;

        vector<vector<int>> id(m, vector<int>(n, -1));

        for(int i = 0; i < total; i++) {
            id[litter[i].first][litter[i].second] = i;
        }
        int full = (1 << total) - 1;

        queue<tuple<int,int,int,int>> q;

        q.push({sr, sc, 0, energy});

        vector<vector<vector<int>>> visited(
            m,
            vector<vector<int>>(n, vector<int>(1 << total, -1))
        );

        visited[sr][sc][0] = energy;

        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        int moves = 0;

        while(!q.empty()) {
            int size = q.size();

            while(size--) {
                auto [r, c, mask, en] = q.front();
                q.pop();

                if(mask == full)
                    return moves;

                for(int d = 0; d < 4; d++) {
                    int nr = r + dr[d];
                    int nc = c + dc[d];

                    if(nr < 0 || nr >= m || nc < 0 || nc >= n)
                        continue;

                    if(classroom[nr][nc] == 'X')
                        continue;

                    if(en == 0)
                        continue;

                    int newEnergy = en - 1;
                    int newMask = mask;

                    if(classroom[nr][nc] == 'L') {
                        int x = id[nr][nc];
                        newMask = mask | (1 << x);
                    }

                    if(classroom[nr][nc] == 'R') {
                        newEnergy = energy;
                    }

                    if(visited[nr][nc][newMask] >= newEnergy)
                        continue;

                    visited[nr][nc][newMask] = newEnergy;

                    q.push({nr, nc, newMask, newEnergy});
                }
            }
            moves++;
        }
        return -1;
    }
};