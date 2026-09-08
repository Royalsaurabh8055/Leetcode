class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        
        int n = nums.size();

        vector<int> dp(n);

        // If only one number is present,
        // current player takes it.
        for (int i = 0; i < n; i++) {
            dp[i] = nums[i];
        }

        // length of current subarray
        for (int len = 2; len <= n; len++) {

            for (int i = 0; i + len <= n; i++) {

                int j = i + len - 1;

                // Take left number
                int left = nums[i] - dp[i + 1];

                // Take right number
                int right = nums[j] - dp[i];

                dp[i] = max(left, right);
            }
        }

        return dp[0] >= 0;
    }
};