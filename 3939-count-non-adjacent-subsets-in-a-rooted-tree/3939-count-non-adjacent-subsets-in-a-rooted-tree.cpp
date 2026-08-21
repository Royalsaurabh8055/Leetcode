class Solution {
public:
    static const int MOD = 1000000007;

    int n, k;
    vector<int> nums;
    vector<vector<int>> tree;

    // dp[u][0][r] -> u not selected
    // dp[u][1][r] -> u selected
    vector<vector<vector<long long>>> dp;

    void dfs(int u) {
        dp[u][0][0] = 1;
        dp[u][1][nums[u] % k] = 1;

        for (int v : tree[u]) {
            dfs(v);

            vector<vector<long long>> next(
                2, vector<long long>(k, 0)
            );

            for (int parentState = 0; parentState <= 1; parentState++) {
                for (int r1 = 0; r1 < k; r1++) {

                    if (dp[u][parentState][r1] == 0)
                        continue;

                    for (int childState = 0; childState <= 1; childState++) {

                        // Adjacent nodes cannot both be selected
                        if (parentState == 1 && childState == 1)
                            continue;

                        for (int r2 = 0; r2 < k; r2++) {

                            int newR = (r1 + r2) % k;

                            next[parentState][newR] =
                                (next[parentState][newR] +
                                 dp[u][parentState][r1] *
                                 dp[v][childState][r2]) % MOD;
                        }
                    }
                }
            }

            dp[u] = next;
        }
    }

    int countValidSubsets(
        vector<int>& parent,
        vector<int>& nums,
        int k
    ) {
        this->n = parent.size();
        this->nums = nums;
        this->k = k;

        tree.assign(n, {});

        for (int i = 1; i < n; i++) {
            tree[parent[i]].push_back(i);
        }

        dp.assign(
            n,
            vector<vector<long long>>(
                2,
                vector<long long>(k, 0)
            )
        );

        dfs(0);

        long long ans =
            (dp[0][0][0] + dp[0][1][0]) % MOD;

        // Remove empty subset
        ans = (ans - 1 + MOD) % MOD;

        return ans;
    }
};