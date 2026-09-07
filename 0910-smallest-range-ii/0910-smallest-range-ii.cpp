class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {

        sort(nums.begin(), nums.end());

        int n = nums.size();

        // Initially, don't change anything
        int ans = nums[n - 1] - nums[0];

        for (int i = 1; i < n; i++) {

            // Left side: increase by k
            // Right side: decrease by k

            int mini = min(nums[0] + k,
                           nums[i] - k);

            int maxi = max(nums[i - 1] + k,
                           nums[n - 1] - k);

            ans = min(ans, maxi - mini);
        }

        return ans;
    }
};