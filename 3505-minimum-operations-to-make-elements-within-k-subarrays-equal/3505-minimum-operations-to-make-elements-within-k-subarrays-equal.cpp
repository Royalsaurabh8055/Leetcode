class Solution {
public:
    using ll = long long;

    struct MedianWindow {
        multiset<int> left, right;
        ll leftSum = 0, rightSum = 0;

        void balance() {
            while(left.size() > right.size() + 1) {
                auto it = prev(left.end());
                int x = *it;

                left.erase(it);
                leftSum -= x;

                right.insert(x);
                rightSum += x;
            }

            while(left.size() < right.size()) {
                auto it = right.begin();
                int x = *it;

                right.erase(it);
                rightSum -= x;

                left.insert(x);
                leftSum += x;
            }
        }

        void add(int x) {
            if(left.empty() || x <= *prev(left.end())) {
                left.insert(x);
                leftSum += x;
            }
            else {
                right.insert(x);
                rightSum += x;
            }

            balance();
        }

        void remove(int x) {
            auto it = left.find(x);

            if(it != left.end()) {
                left.erase(it);
                leftSum -= x;
            }
            else {
                it = right.find(x);
                right.erase(it);
                rightSum -= x;
            }

            balance();
        }

        ll cost() {
            ll median = *prev(left.end());

            ll leftCost =
                median * (ll)left.size() - leftSum;

            ll rightCost =
                rightSum - median * (ll)right.size();

            return leftCost + rightCost;
        }
    };

    long long minOperations(vector<int>& nums, int x, int k) {

        int n = nums.size();

        // cost[i] = minimum operations needed
        // to make nums[i ... i+x-1] equal
        vector<ll> cost(n - x + 1);

        MedianWindow window;

        // First window
        for(int i = 0; i < x; i++) {
            window.add(nums[i]);
        }

        cost[0] = window.cost();

        // Sliding window
        for(int i = x; i < n; i++) {
            window.remove(nums[i - x]);
            window.add(nums[i]);

            cost[i - x + 1] = window.cost();
        }

        // dp[j] = minimum cost after processing current prefix
        // using j windows
        const ll INF = 1e18;

        vector<vector<ll>> dp(k + 1,
                              vector<ll>(n + 1, INF));

        dp[0][0] = 0;

        for(int i = 0; i < n; i++) {

            for(int j = 0; j <= k; j++) {

                if(dp[j][i] == INF)
                    continue;

                // Don't choose window starting at i
                dp[j][i + 1] =
                    min(dp[j][i + 1], dp[j][i]);

                // Choose [i ... i+x-1]
                if(j < k && i + x <= n) {

                    dp[j + 1][i + x] =
                        min(
                            dp[j + 1][i + x],
                            dp[j][i] + cost[i]
                        );
                }
            }
        }

        return dp[k][n];
    }
};