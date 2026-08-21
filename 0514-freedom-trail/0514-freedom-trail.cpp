class Solution {
public:
    int n;
    string ring, key;
    vector<vector<int>> dp;

    int solve(int pos, int idx) {
        if (idx == key.size())
            return 0;

        if (dp[pos][idx] != -1)
            return dp[pos][idx];

        int ans = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (ring[i] == key[idx]) {

                int diff = abs(i - pos);
                int steps = min(diff, n - diff);

                ans = min(ans,
                          steps + 1 + solve(i, idx + 1));
            }
        }

        return dp[pos][idx] = ans;
    }

    int findRotateSteps(string ring, string key) {
        this->ring = ring;
        this->key = key;

        n = ring.size();

        dp.assign(n, vector<int>(key.size(), -1));

        return solve(0, 0);
    }
};