class Solution {
public:
    int getMaxDigit(int x) {
        int mx = 0;

        while (x > 0) {
            mx = max(mx, x % 10);
            x /= 10;
        }

        return mx;
    }

    int maxSum(vector<int>& nums) {
        vector<int> best(10, -1);
        int ans = -1;

        for (int x : nums) {
            int digit = getMaxDigit(x);

            if (best[digit] != -1) {
                ans = max(ans, x + best[digit]);
            }

            best[digit] = max(best[digit], x);
        }

        return ans;
    }
};