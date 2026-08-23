class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {

        int n = moveTime.size();
        int m = moveTime[0].size();

        vector<vector<int>> dist(
            n, vector<int>(m, INT_MAX)
        );

        // {time, {row, col}}
        priority_queue<
            pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>
        > pq;

        dist[0][0] = 0;
        pq.push({0, {0, 0}});

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!pq.empty()) {

            auto [time, pos] = pq.top();
            pq.pop();

            int r = pos.first;
            int c = pos.second;

            if (time > dist[r][c])
                continue;

            if (r == n - 1 && c == m - 1)
                return time;

            for (int k = 0; k < 4; k++) {

                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr < 0 || nr >= n ||
                    nc < 0 || nc >= m)
                    continue;

                // Move cost alternates:
                // first move = 1
                // second move = 2
                // third move = 1
                // ...

                int moveCost = (r + c) % 2 + 1;

                int newTime =
                    max(time, moveTime[nr][nc])
                    + moveCost;

                if (newTime < dist[nr][nc]) {

                    dist[nr][nc] = newTime;

                    pq.push({
                        newTime,
                        {nr, nc}
                    });
                }
            }
        }

        return -1;
    }
};