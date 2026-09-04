class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {

        int n = graph.size();

        // All nodes visited
        int fullMask = (1 << n) - 1;

        // visited[node][mask]
        vector<vector<bool>> visited(
            n, vector<bool>(1 << n, false)
        );

        queue<pair<int, int>> q;

        // We can start from ANY node
        for (int i = 0; i < n; i++) {

            int mask = (1 << i);

            q.push({i, mask});

            visited[i][mask] = true;
        }

        int steps = 0;

        while (!q.empty()) {

            int size = q.size();

            while (size--) {

                int node = q.front().first;
                int mask = q.front().second;

                q.pop();

                // Have we visited every node?
                if (mask == fullMask) {
                    return steps;
                }

                // Go to all neighbours
                for (int next : graph[node]) {

                    // Mark next node as visited
                    int newMask = mask | (1 << next);

                    if (!visited[next][newMask]) {

                        visited[next][newMask] = true;

                        q.push({next, newMask});
                    }
                }
            }

            steps++;
        }

        return -1;
    }
};