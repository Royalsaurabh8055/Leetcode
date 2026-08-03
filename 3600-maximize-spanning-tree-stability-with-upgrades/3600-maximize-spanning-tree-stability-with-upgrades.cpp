class DSU {
public:
    vector<int> parent, sz;

    DSU(int n) {
        parent.resize(n);
        sz.assign(n, 1);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b) return false;

        if (sz[a] < sz[b])
            swap(a, b);

        parent[b] = a;
        sz[a] += sz[b];

        return true;
    }
};

class Solution {
public:
    int maxStability(int n, vector<vector<int>>& edges, int k) {

        DSU dsu(n);

        int components = n;
        int upper = INT_MAX;

        // Add mandatory edges
        for (auto &e : edges) {
            int u = e[0], v = e[1], s = e[2], must = e[3];

            if (must) {
                if (!dsu.unite(u, v))
                    return -1;

                components--;
                upper = min(upper, s);
            }
        }

        // Check if graph can be connected
        for (auto &e : edges) {
            if (dsu.unite(e[0], e[1]))
                components--;
        }

        if (components != 1)
            return -1;

        if (upper == INT_MAX)
            upper = 200000;

        auto check = [&](int lim) {

            DSU uf(n);
            int comp = n;
            int used = 0;

            // Mandatory edges
            for (auto &e : edges) {
                if (e[3]) {
                    if (e[2] < lim)
                        return false;

                    if (!uf.unite(e[0], e[1]))
                        return false;

                    comp--;
                }
            }

            // Optional edges without upgrade
            for (auto &e : edges) {

                if (e[3]) continue;

                if (e[2] >= lim) {

                    if (uf.unite(e[0], e[1]))
                        comp--;
                }
            }

            // Optional edges with upgrade
            for (auto &e : edges) {

                if (e[3]) continue;

                if (e[2] < lim && e[2] * 2 >= lim && used < k) {

                    if (uf.unite(e[0], e[1])) {
                        comp--;
                        used++;
                    }
                }
            }

            return comp == 1;
        };

        int lo = 1, hi = upper, ans = -1;

        while (lo <= hi) {

            int mid = lo + (hi - lo) / 2;

            if (check(mid)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return ans;
    }
};