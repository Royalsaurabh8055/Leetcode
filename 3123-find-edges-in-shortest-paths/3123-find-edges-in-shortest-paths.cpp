class Solution {
public:

    vector<long long> dijkstra(
        int src,
        vector<vector<pair<int,int>>>& adj
    ) {
        int n = adj.size();

        vector<long long> dist(n, LLONG_MAX);

        priority_queue<
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<pair<long long, int>>
        > pq;

        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {

            auto [d, u] = pq.top();
            pq.pop();

            if (d > dist[u])
                continue;

            for (auto [v, w] : adj[u]) {

                if (dist[v] > d + w) {

                    dist[v] = d + w;

                    pq.push({dist[v], v});
                }
            }
        }

        return dist;
    }

    vector<bool> findAnswer(
        int n,
        vector<vector<int>>& edges
    ) {

        vector<vector<pair<int,int>>> adj(n);

        // Build undirected graph
        for (auto& edge : edges) {

            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        // Shortest distance from 0
        vector<long long> distStart =
            dijkstra(0, adj);

        // Shortest distance from n-1
        vector<long long> distEnd =
            dijkstra(n - 1, adj);

        long long shortest = distStart[n - 1];

        vector<bool> ans(edges.size(), false);

        // No path from 0 to n-1
        if (shortest == LLONG_MAX)
            return ans;

        for (int i = 0; i < edges.size(); i++) {

            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];

            // 0 -> u -> v -> n-1
            if (distStart[u] != LLONG_MAX &&
                distEnd[v] != LLONG_MAX &&
                distStart[u] + w + distEnd[v] == shortest) {

                ans[i] = true;
            }

            // 0 -> v -> u -> n-1
            if (distStart[v] != LLONG_MAX &&
                distEnd[u] != LLONG_MAX &&
                distStart[v] + w + distEnd[u] == shortest) {

                ans[i] = true;
            }
        }

        return ans;
    }
};