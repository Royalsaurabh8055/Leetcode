class Solution {
public:
    vector<int> parent, sz;

    int find(int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b) return;

        if (sz[a] < sz[b])
            swap(a, b);

        parent[b] = a;
        sz[a] += sz[b];
    }

    int largestComponentSize(vector<int>& nums) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(), nums.end());

        // Build smallest prime factor array
        vector<int> spf(maxi + 1);

        for (int i = 0; i <= maxi; i++)
            spf[i] = i;

        for (int i = 2; i * i <= maxi; i++) {
            if (spf[i] == i) {
                for (int j = i * i; j <= maxi; j += i) {
                    if (spf[j] == j)
                        spf[j] = i;
                }
            }
        }

        // Initialize DSU
        parent.resize(n);
        sz.assign(n, 1);

        for (int i = 0; i < n; i++)
            parent[i] = i;

        // Store the first index containing each prime factor
        vector<int> primeOwner(maxi + 1, -1);

        for (int i = 0; i < n; i++) {
            int x = nums[i];

            while (x > 1) {
                int p = spf[x];

                if (primeOwner[p] == -1) {
                    primeOwner[p] = i;
                } else {
                    unite(i, primeOwner[p]);
                }

                // Remove all occurrences of this prime
                while (x % p == 0)
                    x /= p;
            }
        }

        // Find the largest component
        int ans = 1;

        for (int i = 0; i < n; i++) {
            if (find(i) == i)
                ans = max(ans, sz[i]);
        }

        return ans;
    }
};