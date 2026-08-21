class Solution {
public:
    vector<vector<int>> adj;
    vector<int> ans;

    vector<int> dfs(int node, int parent, string& labels) {
        vector<int> count(26, 0);

        // Count current node
        count[labels[node] - 'a']++;

        for (int child : adj[node]) {
            if (child == parent)
                continue;

            vector<int> childCount = dfs(child, node, labels);

            // Merge child's frequency
            for (int i = 0; i < 26; i++) {
                count[i] += childCount[i];
            }
        }

        // Frequency of current node's label
        ans[node] = count[labels[node] - 'a'];

        return count;
    }

    vector<int> countSubTrees(
        int n,
        vector<vector<int>>& edges,
        string labels
    ) {
        adj.resize(n);
        ans.resize(n);

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(0, -1, labels);

        return ans;
    }
};