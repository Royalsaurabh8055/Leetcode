class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int n = nums.size();

        // First valid triplet as initial answer
        int ans = nums[0] + nums[1] + nums[2];

        for(int i = 0; i < n - 2; i++) {

            int left = i + 1;
            int right = n - 1;

            while(left < right) {

                int sum = nums[i] + nums[left] + nums[right];

                // Exact answer
                if(sum == target)
                    return sum;

                // Update closest answer
                if(abs(sum - target) < abs(ans - target)) {
                    ans = sum;
                }

                // Need a bigger sum
                if(sum < target) {
                    left++;
                }
                // Need a smaller sum
                else {
                    right--;
                }
            }
        }

        return ans;
    }
};