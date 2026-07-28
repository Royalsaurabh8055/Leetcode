class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {

        int n = nums.size();

        // sum[i] = sum of k elements starting from index i
        vector<int> sum(n - k + 1);

        int windowSum = 0;

        for (int i = 0; i < n; i++) {

            windowSum += nums[i];

            if (i >= k)
                windowSum -= nums[i - k];

            if (i >= k - 1)
                sum[i - k + 1] = windowSum;
        }

        int m = sum.size();

        // left[i] = index of maximum sum window from 0...i
        vector<int> left(m);

        int best = 0;

        for (int i = 0; i < m; i++) {

            if (sum[i] > sum[best])
                best = i;

            left[i] = best;
        }

        // right[i] = index of maximum sum window from i...m-1
        vector<int> right(m);

        best = m - 1;

        for (int i = m - 1; i >= 0; i--) {

            if (sum[i] >= sum[best])
                best = i;

            right[i] = best;
        }

        vector<int> ans(3);
        int maxTotal = -1;

        // Try every possible middle subarray
        for (int mid = k; mid < m - k; mid++) {

            int l = left[mid - k];
            int r = right[mid + k];

            int total = sum[l] + sum[mid] + sum[r];

            if (total > maxTotal) {

                maxTotal = total;

                ans[0] = l;
                ans[1] = mid;
                ans[2] = r;
            }
        }

        return ans;
    }
};