class Solution {
public:

    int n;
    vector<int> suffix;
    vector<vector<int>> dp;

    int solve(int i, int M) {

        // Saare remaining piles le sakte hain
        if(i + 2 * M >= n) {
            return suffix[i];
        }

        // Already calculated
        if(dp[i][M] != -1) {
            return dp[i][M];
        }

        int ans = 0;

        // Current player can take 1 to 2*M piles
        for(int X = 1; X <= 2 * M; X++) {

            int nextM = max(M, X);

            // Total remaining - opponent's best
            int current = suffix[i] - solve(i + X, nextM);

            ans = max(ans, current);
        }

        return dp[i][M] = ans;
    }

    int stoneGameII(vector<int>& piles) {

        n = piles.size();

        // suffix[i] = sum of piles from i to n-1
        suffix.resize(n);

        suffix[n - 1] = piles[n - 1];

        for(int i = n - 2; i >= 0; i--) {
            suffix[i] = piles[i] + suffix[i + 1];
        }

        dp.assign(n, vector<int>(n + 1, -1));

        return solve(0, 1);
    }
};