class Solution {
public:
    int totalStrength(vector<int>& strength) {

        const long long MOD = 1e9 + 7;
        int n = strength.size();

        // Previous smaller element
        vector<int> left(n);

        // Next smaller or equal element
        vector<int> right(n);

        stack<int> st;

        // Find previous strictly smaller element
        for (int i = 0; i < n; i++) {

            while (!st.empty() &&
                   strength[st.top()] >= strength[i]) {
                st.pop();
            }

            left[i] = st.empty() ? -1 : st.top();

            st.push(i);
        }

        while (!st.empty())
            st.pop();

        // Find next smaller or equal element
        for (int i = n - 1; i >= 0; i--) {

            while (!st.empty() &&
                   strength[st.top()] > strength[i]) {
                st.pop();
            }

            right[i] = st.empty() ? n : st.top();

            st.push(i);
        }

        // Prefix sum
        vector<long long> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] =
                (prefix[i] + strength[i]) % MOD;
        }

        // Prefix of prefix sum
        vector<long long> prefix2(n + 2, 0);

        for (int i = 0; i <= n; i++) {
            prefix2[i + 1] =
                (prefix2[i] + prefix[i]) % MOD;
        }

        long long ans = 0;

        for (int i = 0; i < n; i++) {

            int l = left[i];
            int r = right[i];

            long long leftCount = i - l;
            long long rightCount = r - i;

            // Sum of prefix sums on right side
            long long rightSum =
                (prefix2[r + 1] -
                 prefix2[i + 1] + MOD) % MOD;

            // Sum of prefix sums on left side
            long long leftSum =
                (prefix2[i + 1] -
                 prefix2[l + 1] + MOD) % MOD;

            long long contribution =
                (rightSum * leftCount % MOD
                 - leftSum * rightCount % MOD
                 + MOD) % MOD;

            contribution =
                contribution * strength[i] % MOD;

            ans = (ans + contribution) % MOD;
        }

        return ans;
    }
};