class Solution {
public:
    vector<int> tree;

    void update(int node, int l, int r, int pos, int val) {
        if (l == r) {
            tree[node] = val;
            return;
        }

        int mid = (l + r) / 2;

        if (pos <= mid)
            update(node * 2, l, mid, pos, val);
        else
            update(node * 2 + 1, mid + 1, r, pos, val);

        tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
    }

    int query(int node, int l, int r, int qr) {
        if (r <= qr)
            return tree[node];

        int mid = (l + r) / 2;

        if (qr <= mid)
            return query(node * 2, l, mid, qr);

        return max(
            tree[node * 2],
            query(node * 2 + 1, mid + 1, r, qr)
        );
    }

    vector<bool> getResults(vector<vector<int>>& queries) {
        int n = 0;

        for (auto &q : queries)
            n = max(n, q[1]);

        n++;

        tree.assign(4 * n + 5, 0);

        set<int> obstacles;
        obstacles.insert(0);
        obstacles.insert(n);

        vector<bool> ans;

        for (auto &q : queries) {
            int type = q[0];
            int x = q[1];

            auto it = obstacles.lower_bound(x);
            int prevObstacle = *prev(it);
            int nextObstacle = *it;

            if (type == 1) {
                obstacles.insert(x);

                // Gap from previous obstacle to x
                update(
                    1, 0, n,
                    x,
                    x - prevObstacle
                );

                // Gap from x to next obstacle
                update(
                    1, 0, n,
                    nextObstacle,
                    nextObstacle - x
                );
            }
            else {
                int sz = q[2];

                // Maximum gap ending before prevObstacle
                int maxGap = query(
                    1, 0, n,
                    prevObstacle
                );

                // Gap from previous obstacle to x
                maxGap = max(
                    maxGap,
                    x - prevObstacle
                );

                ans.push_back(maxGap >= sz);
            }
        }

        return ans;
    }
};