class Solution {
public:

    struct Node {
        int lmx;   // longest same-character prefix
        int rmx;   // longest same-character suffix
        int mx;    // longest same-character substring

        Node() {
            lmx = rmx = mx = 0;
        }
    };

    vector<Node> tree;
    string s;

    void build(int node, int l, int r) {

        if(l == r) {
            tree[node].lmx = 1;
            tree[node].rmx = 1;
            tree[node].mx = 1;
            return;
        }

        int mid = (l + r) / 2;

        build(node * 2, l, mid);
        build(node * 2 + 1, mid + 1, r);

        merge(node, l, r);
    }

    void merge(int node, int l, int r) {

        int left = node * 2;
        int right = node * 2 + 1;

        tree[node].lmx = tree[left].lmx;
        tree[node].rmx = tree[right].rmx;

        tree[node].mx = max(tree[left].mx, tree[right].mx);

        int mid = (l + r) / 2;

        // Boundary characters are same
        if(s[mid] == s[mid + 1]) {

            // Whole left part is same character
            if(tree[left].lmx == mid - l + 1) {
                tree[node].lmx += tree[right].lmx;
            }

            // Whole right part is same character
            if(tree[right].rmx == r - mid) {
                tree[node].rmx += tree[left].rmx;
            }

            // A repeating substring crosses the middle
            tree[node].mx = max(
                tree[node].mx,
                tree[left].rmx + tree[right].lmx
            );
        }
    }

    void update(int node, int l, int r, int index, char ch) {

        if(l == r) {
            s[index] = ch;

            tree[node].lmx = 1;
            tree[node].rmx = 1;
            tree[node].mx = 1;

            return;
        }

        int mid = (l + r) / 2;

        if(index <= mid) {
            update(node * 2, l, mid, index, ch);
        }
        else {
            update(node * 2 + 1, mid + 1, r, index, ch);
        }

        merge(node, l, r);
    }

    vector<int> longestRepeating(
        string s,
        string queryCharacters,
        vector<int>& queryIndices
    ) {

        this->s = s;

        int n = s.length();

        tree.resize(4 * n + 5);

        build(1, 0, n - 1);

        vector<int> ans;

        for(int i = 0; i < queryIndices.size(); i++) {

            int index = queryIndices[i];

            char ch = queryCharacters[i];

            update(1, 0, n - 1, index, ch);

            ans.push_back(tree[1].mx);
        }

        return ans;
    }
};