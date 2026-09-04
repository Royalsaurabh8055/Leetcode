class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {

        // Create graph
        vector<vector<int>> graph(n + 1);

        for (auto path : paths) {

            int u = path[0];
            int v = path[1];

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        // answer[i] = flower type of garden i
        vector<int> answer(n + 1, 0);

        // Process every garden
        for (int i = 1; i <= n; i++) {

            bool used[5] = {false};

            // Check flowers used by neighbours
            for (int neighbour : graph[i]) {

                if (answer[neighbour] != 0) {
                    used[answer[neighbour]] = true;
                }
            }

            // Choose first flower not used
            for (int flower = 1; flower <= 4; flower++) {

                if (!used[flower]) {
                    answer[i] = flower;
                    break;
                }
            }
        }

        // Remove index 0
        vector<int> result;

        for (int i = 1; i <= n; i++) {
            result.push_back(answer[i]);
        }

        return result;
    }
};