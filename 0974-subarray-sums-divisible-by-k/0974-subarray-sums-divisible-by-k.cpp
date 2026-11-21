class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> freq(k, 0);

        freq[0] = 1;

        int prefixSum = 0;
        int ans = 0;

        for (int num : nums) {
            prefixSum = (prefixSum + num) % k;

            // Handle negative remainder
            if (prefixSum < 0)
                prefixSum += k;

            ans += freq[prefixSum];

            freq[prefixSum]++;
        }

        return ans;
    }
};