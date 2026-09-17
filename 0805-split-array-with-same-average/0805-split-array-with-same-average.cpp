class Solution {
public:
    bool splitArraySameAverage(vector<int>& nums) {

        int n = nums.size();

        int total = 0;

        for(int x : nums)
            total += x;

        // dp[k] = possible sums using exactly k elements
        vector<unordered_set<int>> dp(n / 2 + 1);

        dp[0].insert(0);

        for(int x : nums) {

            // Reverse order so same element is not used twice
            for(int k = n / 2; k >= 1; k--) {

                for(int sum : dp[k - 1]) {

                    dp[k].insert(sum + x);
                }
            }
        }

        // Try subset sizes from 1 to n/2
        for(int k = 1; k <= n / 2; k++) {

            if((total * k) % n != 0)
                continue;

            int requiredSum = (total * k) / n;

            if(dp[k].find(requiredSum) != dp[k].end())
                return true;
        }

        return false;
    }
};