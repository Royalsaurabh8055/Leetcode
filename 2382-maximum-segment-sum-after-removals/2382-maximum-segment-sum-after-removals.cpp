class Solution {
public:

    vector<int> parent;
    vector<long long> sum;

    int find(int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {

        int rootA = find(a);
        int rootB = find(b);

        if (rootA == rootB)
            return;

        parent[rootB] = rootA;
        sum[rootA] += sum[rootB];
    }

    vector<long long> maximumSegmentSum(
        vector<int>& nums,
        vector<int>& removeQueries
    ) {

        int n = nums.size();

        parent.resize(n);
        sum.resize(n, 0);

        vector<bool> active(n, false);

        vector<long long> ans(n, 0);

        long long maxSum = 0;

        // Process removals in reverse
        for (int i = n - 1; i >= 0; i--) {

            // Answer BEFORE adding current element back
            ans[i] = maxSum;

            int index = removeQueries[i];

            // Activate element
            active[index] = true;
            parent[index] = index;
            sum[index] = nums[index];

            // Connect with left neighbor
            if (index > 0 && active[index - 1]) {
                unite(index, index - 1);
            }

            // Connect with right neighbor
            if (index + 1 < n && active[index + 1]) {
                unite(index, index + 1);
            }

            // Find sum of newly created segment
            int root = find(index);

            maxSum = max(maxSum, sum[root]);
        }

        return ans;
    }
};