class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges,
                vector<int>& passingFees) {

        int n = passingFees.size();
        const int INF = 1e9;

        // dp[t][u] = minimum cost to reach city u
        // in exactly t minutes
        vector<vector<int>> dp(
            maxTime + 1,
            vector<int>(n, INF)
        );

        // We start at city 0
        // and pay its fee
        dp[0][0] = passingFees[0];

        for (int t = 1; t <= maxTime; t++) {

            for (auto &edge : edges) {

                int u = edge[0];
                int v = edge[1];
                int travelTime = edge[2];

                if (travelTime <= t) {

                    // u -> v
                    if (dp[t - travelTime][u] != INF) {
                        dp[t][v] = min(
                            dp[t][v],
                            dp[t - travelTime][u]
                            + passingFees[v]
                        );
                    }

                    // v -> u
                    if (dp[t - travelTime][v] != INF) {
                        dp[t][u] = min(
                            dp[t][u],
                            dp[t - travelTime][v]
                            + passingFees[u]
                        );
                    }
                }
            }
        }

        int ans = INF;

        // We need <= maxTime, not exactly maxTime
        for (int t = 0; t <= maxTime; t++) {
            ans = min(ans, dp[t][n - 1]);
        }

        return ans == INF ? -1 : ans;
    }
};