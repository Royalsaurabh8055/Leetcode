class Solution {
public:

    // BFS from one node
    // Returns maximum number of levels
    // Returns -1 if component is not bipartite
    int bfs(int start, vector<vector<int>>& graph) {

        int n = graph.size();

        vector<int> color(n, -1);
        vector<int> level(n, 0);

        queue<int> q;

        q.push(start);
        color[start] = 0;
        level[start] = 1;

        int maxLevel = 1;

        while (!q.empty()) {

            int node = q.front();
            q.pop();

            for (int next : graph[node]) {

                // First time visiting next
                if (color[next] == -1) {

                    color[next] = 1 - color[node];

                    level[next] = level[node] + 1;

                    maxLevel = max(maxLevel, level[next]);

                    q.push(next);
                }

                // Adjacent nodes have same color
                else if (color[next] == color[node]) {

                    return -1;
                }
            }
        }

        return maxLevel;
    }


    int magnificentSets(int n, vector<vector<int>>& edges) {

        // Build graph
        vector<vector<int>> graph(n + 1);

        for (auto edge : edges) {

            int u = edge[0];
            int v = edge[1];

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        // Find connected components
        vector<bool> visited(n + 1, false);

        int answer = 0;

        for (int i = 1; i <= n; i++) {

            if (visited[i])
                continue;

            // Find all nodes of this component
            vector<int> component;

            queue<int> q;

            q.push(i);
            visited[i] = true;

            while (!q.empty()) {

                int node = q.front();
                q.pop();

                component.push_back(node);

                for (int next : graph[node]) {

                    if (!visited[next]) {

                        visited[next] = true;
                        q.push(next);
                    }
                }
            }

            // Try BFS from every node
            int best = 0;

            for (int node : component) {

                int groups = bfs(node, graph);

                // Not bipartite
                if (groups == -1)
                    return -1;

                best = max(best, groups);
            }

            // Add this component's maximum groups
            answer += best;
        }

        return answer;
    }
};