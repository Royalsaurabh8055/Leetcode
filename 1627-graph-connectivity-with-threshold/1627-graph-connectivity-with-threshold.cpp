class Solution {
public:
    vector<int> parent, rank;

    int find(int x)
    {
        if(parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    void Union(int x, int y)
    {
        int px = find(x);
        int py = find(y);

        if(px == py)
            return;

        if(rank[px] < rank[py])
        {
            parent[px] = py;
        }
        else if(rank[px] > rank[py])
        {
            parent[py] = px;
        }
        else
        {
            parent[py] = px;
            rank[px]++;
        }
    }

    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {

        parent.resize(n + 1);
        rank.resize(n + 1, 0);

        for(int i = 1; i <= n; i++)
            parent[i] = i;

        for(int i = threshold + 1; i <= n; i++)
        {
            for(int multiple = 2 * i; multiple <= n; multiple += i)
            {
                Union(i, multiple);
            }
        }

        vector<bool> ans;

        for(auto &q : queries)
        {
            if(find(q[0]) == find(q[1]))
                ans.push_back(true);
            else
                ans.push_back(false);
        }

        return ans;
    }
};