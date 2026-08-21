class Solution {
public:
    vector<int> parent;

    int find(int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    bool unite(int u, int v) {
        int pu = find(u);
        int pv = find(v);

        if (pu == pv)
            return false;   // cycle

        parent[pv] = pu;
        return true;
    }

    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        // Check if any node has two parents
        vector<int> indegree(n + 1, -1);

        int candidate1 = -1;
        int candidate2 = -1;

        for (int i = 0; i < n; i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            if (indegree[v] != -1) {
                candidate1 = indegree[v];
                candidate2 = i;
                break;
            }

            indegree[v] = i;
        }

        // DSU initialization
        parent.resize(n + 1);

        for (int i = 0; i <= n; i++)
            parent[i] = i;

        // Try all edges except candidate2
        for (int i = 0; i < n; i++) {

            if (i == candidate2)
                continue;

            int u = edges[i][0];
            int v = edges[i][1];

            if (!unite(u, v)) {
                // Cycle found
                if (candidate1 == -1)
                    return edges[i];

                return edges[candidate1];
            }
        }

        // Two parents but no cycle
        return edges[candidate2];
    }
};