class Solution {
public:
    long long kthSmallestProduct(vector<int>& nums1,
                                 vector<int>& nums2,
                                 long long k) {

        int n = nums2.size();

        long long mx =
            max(abs((long long)nums1.front()),
                abs((long long)nums1.back())) *
            max(abs((long long)nums2.front()),
                abs((long long)nums2.back()));

        long long low = -mx;
        long long high = mx;

        // Count products <= x
        auto count = [&](long long x) -> long long {

            long long cnt = 0;

            for (long long a : nums1) {

                // a > 0:
                // product increases as nums2 increases
                if (a > 0) {

                    int l = 0, r = n;

                    while (l < r) {
                        int mid = l + (r - l) / 2;

                        if (a * nums2[mid] <= x)
                            l = mid + 1;
                        else
                            r = mid;
                    }

                    cnt += l;
                }

                // a < 0:
                // product decreases as nums2 increases
                else if (a < 0) {

                    int l = 0, r = n;

                    while (l < r) {
                        int mid = l + (r - l) / 2;

                        if (a * nums2[mid] <= x)
                            r = mid;
                        else
                            l = mid + 1;
                    }

                    cnt += n - l;
                }

                // a == 0
                else {
                    if (x >= 0)
                        cnt += n;
                }
            }

            return cnt;
        };

        // Binary search for kth smallest product
        while (low < high) {

            long long mid = low + (high - low) / 2;

            if (count(mid) >= k)
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
};