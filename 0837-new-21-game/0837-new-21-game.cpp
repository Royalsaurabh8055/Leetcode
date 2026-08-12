class Solution {
public:
    double new21Game(int n, int k, int maxPts) {

        // Alice doesn't draw anything
        if (k == 0)
            return 1.0;

        // Maximum possible final score is:
        // (k - 1) + maxPts
        // If even that is <= n, we always win.
        if (n >= k - 1 + maxPts)
            return 1.0;

        vector<double> dp(n + 1, 0.0);

        // Probability of having 0 points
        dp[0] = 1.0;

        double windowSum = 1.0;
        double ans = 0.0;

        for (int i = 1; i <= n; i++) {

            // Probability of reaching score i
            dp[i] = windowSum / maxPts;

            // If i is a stopping score, it contributes
            // to our answer.
            if (i >= k)
                ans += dp[i];

            // Only scores < k can continue drawing.
            if (i < k)
                windowSum += dp[i];

            // Remove the score that is now outside
            // the sliding window.
            if (i >= maxPts)
                windowSum -= dp[i - maxPts];
        }

        return ans;
    }
};