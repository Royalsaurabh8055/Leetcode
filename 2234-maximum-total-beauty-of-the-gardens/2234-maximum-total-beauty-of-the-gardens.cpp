class Solution {
public:
    long long maximumBeauty(vector<int>& flowers,
                            long long newFlowers,
                            int target,
                            int full,
                            int partial) {

        int n = flowers.size();

        // Anything above target gives no extra benefit
        for (int &x : flowers) {
            x = min(x, target);
        }

        sort(flowers.begin(), flowers.end());

        // Prefix sums
        vector<long long> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + flowers[i];
        }

        long long ans = 0;

        // Number of gardens that are NOT full
        int last = lower_bound(flowers.begin(),
                               flowers.end(),
                               target) - flowers.begin();

        // Cost to make gardens [last ... n-1] full
        long long costFull = 0;

        for (int i = last; i >= 0; i--) {

            // Gardens from i to n-1 are full
            int fullCount = n - i;

            if (costFull <= newFlowers) {

                long long remaining = newFlowers - costFull;

                long long minIncomplete = 0;

                // There are incomplete gardens [0 ... i-1]
                if (i > 0 && partial > 0) {

                    long long low = 0;
                    long long high = target - 1;

                    while (low <= high) {

                        long long mid = low + (high - low) / 2;

                        int pos = upper_bound(
                            flowers.begin(),
                            flowers.begin() + i,
                            mid
                        ) - flowers.begin();

                        // Flowers needed to raise all values
                        // before pos to mid
                        long long needed =
                            mid * pos - prefix[pos];

                        if (needed <= remaining) {
                            minIncomplete = mid;
                            low = mid + 1;
                        }
                        else {
                            high = mid - 1;
                        }
                    }
                }

                long long beauty =
                    1LL * fullCount * full;

                if (i > 0) {
                    beauty += minIncomplete * partial;
                }

                ans = max(ans, beauty);
            }

            // Prepare cost for next iteration:
            // make garden i-1 full
            if (i > 0) {
                costFull += target - flowers[i - 1];
            }
        }

        return ans;
    }
};