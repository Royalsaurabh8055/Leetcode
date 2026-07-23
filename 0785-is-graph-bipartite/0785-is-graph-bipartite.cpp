class Solution {
public:

    bool dfs(int node, int currColor,
             vector<int>& color,
             vector<vector<int>>& graph)
    {
        color[node] = currColor;

        for(int neighbour : graph[node])
        {
            if(color[neighbour] == -1)
            {
                if(!dfs(neighbour, 1 - currColor, color, graph))
                    return false;
            }
            else if(color[neighbour] == currColor)
            {
                return false;
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph)
    {
        int n = graph.size();

        vector<int> color(n, -1);

        for(int i = 0; i < n; i++)
        {
            if(color[i] == -1)
            {
                if(!dfs(i, 0, color, graph))
                    return false;
            }
        }

        return true;
    }
};