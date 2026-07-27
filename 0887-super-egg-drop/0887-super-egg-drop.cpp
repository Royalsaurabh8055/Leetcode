class Solution {
public:
    vector<vector<int>> dp;

    int solve(int eggs, int floors) {

        if (floors == 0 || floors == 1)
            return floors;

        if (eggs == 1)
            return floors;

        if (dp[eggs][floors] != -1)
            return dp[eggs][floors];

        int low = 1;
        int high = floors;
        int ans = INT_MAX;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            int broken = solve(eggs - 1, mid - 1);
            int notBroken = solve(eggs, floors - mid);

            int temp = 1 + max(broken, notBroken);

            ans = min(ans, temp);

            if (broken < notBroken)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return dp[eggs][floors] = ans;
    }

    int superEggDrop(int k, int n) {

        dp.assign(k + 1, vector<int>(n + 1, -1));

        return solve(k, n);
    }
};