class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {

        int m = heightMap.size();
        int n = heightMap[0].size();

        if (m <= 2 || n <= 2)
            return 0;

        // {height, row, col}
        priority_queue<
            tuple<int, int, int>,
            vector<tuple<int, int, int>>,
            greater<tuple<int, int, int>>
        > pq;

        vector<vector<bool>> visited(
            m, vector<bool>(n, false)
        );

        // Put all boundary cells into min heap
        for (int i = 0; i < m; i++) {

            pq.push({heightMap[i][0], i, 0});
            pq.push({heightMap[i][n - 1], i, n - 1});

            visited[i][0] = true;
            visited[i][n - 1] = true;
        }

        for (int j = 1; j < n - 1; j++) {

            pq.push({heightMap[0][j], 0, j});
            pq.push({heightMap[m - 1][j], m - 1, j});

            visited[0][j] = true;
            visited[m - 1][j] = true;
        }

        int water = 0;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!pq.empty()) {

            auto [height, r, c] = pq.top();
            pq.pop();

            for (int k = 0; k < 4; k++) {

                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr < 0 || nr >= m ||
                    nc < 0 || nc >= n ||
                    visited[nr][nc])
                    continue;

                visited[nr][nc] = true;

                int neighborHeight = heightMap[nr][nc];

                // Water trapped here
                if (neighborHeight < height) {
                    water += height - neighborHeight;
                }

                // Effective boundary height
                int newHeight = max(height, neighborHeight);

                pq.push({newHeight, nr, nc});
            }
        }

        return water;
    }
};