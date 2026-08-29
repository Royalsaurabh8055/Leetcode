class Solution {
public:

    vector<int> parent;

    // Find the parent of a node
    int find(int x) {

        if (parent[x] == x) {
            return x;
        }

        return parent[x] = find(parent[x]);
    }

    // Join two groups
    void unite(int a, int b) {

        int rootA = find(a);
        int rootB = find(b);

        if (rootA != rootB) {
            parent[rootA] = rootB;
        }
    }

    string smallestStringWithSwaps(
        string s,
        vector<vector<int>>& pairs
    ) {

        int n = s.size();

        // Initially every index is its own group
        parent.resize(n);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        // Create connected groups
        for (auto p : pairs) {
            unite(p[0], p[1]);
        }

        // Store characters belonging to each group
        unordered_map<int, vector<char>> groups;

        for (int i = 0; i < n; i++) {

            int root = find(i);

            groups[root].push_back(s[i]);
        }

        // Sort every group
        for (auto& it : groups) {

            sort(it.second.begin(), it.second.end());
        }

        // Put smallest characters back
        for (int i = 0; i < n; i++) {

            int root = find(i);

            s[i] = groups[root][0];

            groups[root].erase(groups[root].begin());
        }

        return s;
    }
};