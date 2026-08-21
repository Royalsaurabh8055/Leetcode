class SegmentTree {
public:
    int n;
    vector<int> tree;

    SegmentTree(vector<int>& baskets) {
        n = baskets.size();
        tree.resize(4 * n);
        build(0, 0, n - 1, baskets);
    }

    void build(int node, int l, int r, vector<int>& baskets) {
        if (l == r) {
            tree[node] = baskets[l];
            return;
        }

        int mid = l + (r - l) / 2;

        build(2 * node + 1, l, mid, baskets);
        build(2 * node + 2, mid + 1, r, baskets);

        tree[node] = max(tree[2 * node + 1],
                         tree[2 * node + 2]);
    }

    // Find leftmost basket with capacity >= target
    int query(int node, int l, int r, int target) {

        // No basket in this range can fit
        if (tree[node] < target)
            return -1;

        // Found the basket
        if (l == r)
            return l;

        int mid = l + (r - l) / 2;

        // IMPORTANT:
        // Search left first because we need
        // the LEFTMOST available basket.
        if (tree[2 * node + 1] >= target) {
            return query(2 * node + 1,
                         l,
                         mid,
                         target);
        }

        return query(2 * node + 2,
                     mid + 1,
                     r,
                     target);
    }

    void update(int node, int l, int r, int index) {

        if (l == r) {
            // Mark basket as used
            tree[node] = 0;
            return;
        }

        int mid = l + (r - l) / 2;

        if (index <= mid) {
            update(2 * node + 1,
                   l,
                   mid,
                   index);
        } else {
            update(2 * node + 2,
                   mid + 1,
                   r,
                   index);
        }

        tree[node] = max(tree[2 * node + 1],
                         tree[2 * node + 2]);
    }

    int query(int target) {
        return query(0, 0, n - 1, target);
    }

    void update(int index) {
        update(0, 0, n - 1, index);
    }
};


class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits,
                            vector<int>& baskets) {

        SegmentTree st(baskets);

        int ans = 0;

        for (int fruit : fruits) {

            // Find leftmost basket
            // with capacity >= fruit
            int index = st.query(fruit);

            if (index == -1) {
                // No suitable basket
                ans++;
            } else {
                // Use this basket
                st.update(index);
            }
        }

        return ans;
    }
};