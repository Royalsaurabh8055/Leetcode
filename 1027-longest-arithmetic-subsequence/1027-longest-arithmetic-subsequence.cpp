class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();

        vector<unordered_map<int, int>> dp(n);
        int ans = 2;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {

                int diff = nums[i] - nums[j];

                int len = 2;

                if (dp[j].count(diff)) {
                    len = dp[j][diff] + 1;
                }

                dp[i][diff] = max(dp[i][diff], len);

                ans = max(ans, dp[i][diff]);
            }
        }

        return ans;
    }
};