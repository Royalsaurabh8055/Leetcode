class Solution {
public:
    int maxPerformance(int n, vector<int>& speed,
                       vector<int>& efficiency, int k) {

        const long long MOD = 1e9 + 7;

        vector<pair<int, int>> engineers;

        for(int i = 0; i < n; i++) {
            engineers.push_back({efficiency[i], speed[i]});
        }

        // Efficiency descending
        sort(engineers.begin(), engineers.end(),
             [](auto &a, auto &b) {
                 return a.first > b.first;
             });

        priority_queue<int, vector<int>, greater<int>> pq;

        long long speedSum = 0;
        long long ans = 0;

        for(auto &engineer : engineers) {

            int eff = engineer.first;
            int spd = engineer.second;

            pq.push(spd);
            speedSum += spd;

            // Keep only k engineers
            if(pq.size() > k) {
                speedSum -= pq.top();
                pq.pop();
            }

            // Current engineer has minimum efficiency
            ans = max(ans, speedSum * eff);
        }

        return ans % MOD;
    }
};