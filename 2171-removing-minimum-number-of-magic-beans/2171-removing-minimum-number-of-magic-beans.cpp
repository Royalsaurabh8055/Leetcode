class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        sort(beans.begin(), beans.end());

        int n = beans.size();

        long long total = 0;
        for(int x : beans)
            total += x;

        long long ans = total;

        for(int i = 0; i < n; i++) {
            long long keep = 1LL * beans[i] * (n - i);

            long long remove = total - keep;

            ans = min(ans, remove);
        }

        return ans;
    }
};