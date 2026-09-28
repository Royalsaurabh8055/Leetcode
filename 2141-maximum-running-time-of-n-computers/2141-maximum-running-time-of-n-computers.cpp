class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long total = 0;

        for (int battery : batteries) {
            total += battery;
        }

        long long low = 0;
        long long high = total / n;

        while (low < high) {
            long long mid = low + (high - low + 1) / 2;

            long long available = 0;

            for (int battery : batteries) {
                available += min((long long)battery, mid);
            }

            if (available >= mid * n) {
                low = mid;
            } else {
                high = mid - 1;
            }
        }

        return low;
    }
};