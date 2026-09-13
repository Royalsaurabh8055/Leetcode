class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        int totalKeys = 0;
        int startX = 0;
        int startY = 0;

        // Find starting point and number of keys
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == '@') {
                    startX = i;
                    startY = j;
                }

                if (grid[i][j] >= 'a' && grid[i][j] <= 'f') {
                    totalKeys++;
                }
            }
        }

        int fullMask = (1 << totalKeys) - 1;

        // visited[x][y][keys]
        vector<vector<vector<bool>>> visited(
            m,
            vector<vector<bool>>(n, vector<bool>(1 << totalKeys, false))
        );

        queue<tuple<int, int, int>> q;

        // x, y, keys
        q.push({startX, startY, 0});
        visited[startX][startY][0] = true;

        int steps = 0;

        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        while (!q.empty()) {

            int size = q.size();

            while (size--) {

                auto [x, y, mask] = q.front();
                q.pop();

                // Got all keys
                if (mask == fullMask)
                    return steps;

                for (int d = 0; d < 4; d++) {

                    int nx = x + dx[d];
                    int ny = y + dy[d];

                    // Outside grid
                    if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                        continue;

                    char ch = grid[nx][ny];

                    // Wall
                    if (ch == '#')
                        continue;

                    int newMask = mask;

                    // Key
                    if (ch >= 'a' && ch <= 'f') {

                        int key = ch - 'a';

                        newMask = mask | (1 << key);
                    }

                    // Lock
                    if (ch >= 'A' && ch <= 'F') {

                        int key = ch - 'A';

                        // Don't have the key
                        if ((mask & (1 << key)) == 0)
                            continue;
                    }

                    // New state
                    if (!visited[nx][ny][newMask]) {

                        visited[nx][ny][newMask] = true;

                        q.push({nx, ny, newMask});
                    }
                }
            }

            steps++;
        }

        return -1;
    }
};