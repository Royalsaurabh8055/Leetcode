class Solution {
public:
    int sumSubseqWidths(vector<int>& nums) {

        const long long MOD = 1000000007;

        int n = nums.size();

        sort(nums.begin(), nums.end());

        // powers[i] = 2^i
        vector<long long> powers(n);

        powers[0] = 1;

        for(int i = 1; i < n; i++) {
            powers[i] = (powers[i - 1] * 2) % MOD;
        }

        long long ans = 0;

        for(int i = 0; i < n; i++) {

            long long maximumWays = powers[i];

            long long minimumWays = powers[n - 1 - i];

            long long contribution =
                nums[i] * (maximumWays - minimumWays);

            ans = (ans + contribution) % MOD;
        }

        return ans;
    }
};