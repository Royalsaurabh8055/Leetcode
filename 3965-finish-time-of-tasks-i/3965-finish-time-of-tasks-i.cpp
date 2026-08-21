class Solution {
public:

    long long dfs(int node,
                  vector<vector<int>>& adj,
                  vector<int>& baseTime) {

        // Leaf node
        if (adj[node].empty()) {
            return baseTime[node];
        }

        long long earliest = LLONG_MAX;
        long long latest = LLONG_MIN;

        // Calculate finish time of children
        for (int child : adj[node]) {

            long long finish = dfs(child, adj, baseTime);

            earliest = min(earliest, finish);
            latest = max(latest, finish);
        }

        // ownDuration = (latest - earliest) + baseTime[node]
        long long ownDuration =
            (latest - earliest) + baseTime[node];

        // Finish time of current task
        return latest + ownDuration;
    }

    long long finishTime(int n,
                         vector<vector<int>>& edges,
                         vector<int>& baseTime) {

        vector<vector<int>> adj(n);

        // Build tree
        for (auto& edge : edges) {
            int parent = edge[0];
            int child = edge[1];

            adj[parent].push_back(child);
        }

        return dfs(0, adj, baseTime);
    }
};