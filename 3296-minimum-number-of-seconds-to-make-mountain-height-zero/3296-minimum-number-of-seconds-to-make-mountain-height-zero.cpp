class Solution {
public:
    using ll = long long;

    bool canFinish(vector<int>& workerTimes, int mountainHeight, ll seconds) {

        ll total = 0;

        for (int t : workerTimes) {

            // Solve: t * k * (k + 1) / 2 <= seconds
            ll low = 0, high = mountainHeight;

            while (low <= high) {

                ll mid = (low + high) / 2;

                if ((ll)t * mid * (mid + 1) / 2 <= seconds)
                    low = mid + 1;
                else
                    high = mid - 1;
            }

            total += high;

            if (total >= mountainHeight)
                return true;
        }

        return false;
    }

    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {

        ll left = 0;
        ll right = 1LL * (*min_element(workerTimes.begin(), workerTimes.end()))
                   * mountainHeight * (mountainHeight + 1) / 2;

        ll ans = right;

        while (left <= right) {

            ll mid = left + (right - left) / 2;

            if (canFinish(workerTimes, mountainHeight, mid)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return ans;
    }
};